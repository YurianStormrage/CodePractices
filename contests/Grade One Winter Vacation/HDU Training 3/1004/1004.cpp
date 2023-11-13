#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)5e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n, p;
int a[N];
int f[N], dp[N];
int main()
{
    for(int T = read(); T--;)
    {
        n = read(); p = read();
        for(int i = 0; i <= n; ++i) dp[i] = 0;
        for(int i = 0; i < p; ++i) f[i] = 0;
        int tmp = 0;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i-1];
            tmp = (tmp + read()) % p;
            if(!tmp) dp[i] = max(dp[i], 1);
            if(f[tmp]) dp[i] = max(dp[i], dp[f[tmp]] + 1);
            f[tmp] = i;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}