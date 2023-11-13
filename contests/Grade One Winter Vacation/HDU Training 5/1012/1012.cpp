#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)5e6+2, mod = 998244353;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n;

ll fac[N], inv[N];

void init(int n)
{
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i-1] * i % mod;
    inv[1] = 1;
    for(int i = 2; i <= n; ++i) inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
}

ll pow(ll x, int y)
{
    ll res = 1;
    ll tmp = x;
    while(y)
    {
        if(y & 1) (res *= tmp) %= mod;
        (tmp *= tmp) %= mod;
        y >>= 1;
    }
    return res;
}

int main()
{
    init(N - 2);
    for(int T = read(); T--;)
    {
        n = read();
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        int k = n >> 1;
        for(int i = 1; i <= k; ++i) printf("0 ");
        ll b = fac[k];
        ll all = b;
        for(int i = 1; i <= k; ++i)
        {
            b = b * (i + k) % mod * inv[i << 1] % mod;
            (all += b) %= mod;
        }
        all = pow(all, mod-2);
        b = fac[k];
        printf("%lld ", b*all%mod);
        for(int i = 1; i < k; ++i)
        {
            b = b * (i + k) % mod * inv[i << 1] % mod;
            printf("%lld ", b*all%mod);
        }
        printf("%lld", b*all%mod);
        printf("\n");
    }
    return 0;
}