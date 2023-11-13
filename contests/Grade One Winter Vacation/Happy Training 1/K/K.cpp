#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 2502;
const int mod = (int)1e9 + 7;

int n, k;
int fac[N], inv[N];
ll ans;

inline int Max(int a, int b) {return a > b ? a : b;}
inline int Min(int a, int b) {return a < b ? a : b;}
inline int C(int a, int b) {return (ll)fac[a]*inv[b]%mod*inv[a-b]%mod;}
inline int pow(int x, int a)
{
    int ans = 1, tmp = x;
    while(a)
    {
        if(a & 1) ans = (ll)ans * tmp % mod;
        tmp = (ll)tmp * tmp % mod;
        a >>= 1;
    }
    return ans;
}

inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return x;
    return -x;
}

int main()
{
    n = read(); k = read();
    for(int i = 1; i < n; ++i) read();
    fac[0] = 1;
    for(int i = 1; i <= k; ++i) fac[i] = (ll)fac[i-1] * i % mod;
    inv[k] = pow(fac[k], mod-2);
    for(int i = k-1; i >= 0; --i) inv[i] = (ll)inv[i+1] * (i+1) % mod;
    for(int i = 2; i <= k; ++i)
    {
        if(k - i & 1) ans += mod - (ll)C(k, i) * pow(i-1, n-1) % mod * i % mod;
        else ans += (ll)C(k, i) * pow(i-1, n-1) % mod * i % mod;
        ans %= mod;
    }
    printf("%d", ans);
    return 0;
}