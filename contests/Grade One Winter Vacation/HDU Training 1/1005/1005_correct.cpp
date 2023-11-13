#include <cstdio>
typedef long long ll;
const int K = (int)1e5+2, mod = (int)1e9+9;
const int A = 691504013, B = 308495997;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

ll n, c;
int k;
ll a, b, fa[K], fb[K];
ll fac[K], inv[K];

inline void init()
{
    fac[0] = 1;
    for(int i = 1; i < K; ++i) fac[i] = fac[i-1] * i % mod;
    inv[1] = 1; inv[0] = 1;
    for (int i = 2; i < K; ++i) inv[i] = (mod-mod/i) * inv[mod%i] % mod;
    for (int i = 1; i < K; ++i) inv[i] = inv[i] * inv[i-1] % mod;
}

inline ll C(int n, int m) {return fac[n]*inv[n-m]%mod*inv[m]%mod;}

inline ll pow(ll a,ll b)
{
    ll res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if(b & 1)
            res = res * a % mod;
    return res;
}

int main()
{
    init();

    int T = read();
    while(T--)
    {
        n = read(); c = read(); k = read();

        a = pow(A, c); b = pow(B, c);
        fa[0] = 1; fb[0] = 1;
        for(int i = 1; i <= k; ++i)
        {
            fa[i] = fa[i-1] * a % mod;
            fb[i] = fb[i-1] * b % mod;
        }

        ll t, tmp, ans = 0;
        for(int i = 0; i <= k; ++i)
        {
            t = fa[k-i] * fb[i] % mod;
            if(t == 1) tmp = n % mod;
            else tmp = t * (pow(t, n) - 1 + mod) % mod * pow(t-1, mod-2) % mod;
            if(i & 1) ans = (ans + (mod - C(k, i) * tmp % mod)) % mod;
            else ans = (ans + C(k, i) * tmp % mod) % mod;
        }

        ans = ans * pow(276601605, k) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}