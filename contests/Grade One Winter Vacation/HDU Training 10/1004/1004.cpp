#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)5002, mod = 1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? -x : x;
}
int n;
int f[N][N];
int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= i; ++j) f[i][j] = 0;
        f[1][1] = 1;
        for(int i = 1, b; i < n; ++i)
        {
            b = read();
            for(int j = 1; j <= i; ++j)
                (f[i][j] += f[i][j-1]) >= mod ? f[i][j] -= mod : 1;
            if(b)
                for(int j = 1; j <= i; ++j)
                {
                    (f[i+1][1] += f[i][j]) >= mod ? f[i+1][1] -= mod : 1;
                    f[i+1][j+1] = mod - f[i][j];
                }
            else
                for(int j = 1; j <= i; ++j)
                    (f[i+1][j+1] += f[i][j]) >= mod ? f[i+1][j+1] -= mod : 1;
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            (f[n][i] += f[n][i-1]) >= mod ? f[n][i] -= mod : 0;
            ans += f[n][i];
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}