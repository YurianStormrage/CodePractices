#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int x, y, a, b, c, d;
int p[30], q[30], r[30];
int f[30], g[30], s[30], t[30];
ll ans;

ll pow(int x, ll y)
{
    ll res = 1, tmp = x;
    for(; y; y >>= 1)
    {
        if(y & 1) (res *= tmp) %= mod;
        (tmp *= tmp) %= mod;
    }
    return res;
}

int main()
{
    a = read(); b = read(); c = read(); d = read();
    x = read(); y = read();
    int k = 0;
    for(int i = 2, lim = sqrt(x); i <= lim; ++i)
    {
        if(x % i == 0) p[++k] = i;
        while(x % i == 0) x /= i, ++f[k];
    }
    if(x > 1) {p[++k] = x; f[k] = 1;}
    p[0] = k; k = 0;
    for(int i = 2, lim = sqrt(y); i <= lim; ++i)
    {
        if(y % i == 0) q[++k] = i;
        while(y % i == 0) y /= i, ++g[k];
    }
    if(y > 1) {q[++k] = y; g[k] = 1;}
    q[0] = k; k = 0;
    for(int i = 1, j = 1; i <= p[0]; ++i)
    {
        while(j <= q[0] && p[i] > q[j]) ++j;
        if(j > q[0]) break;
        if(p[i] == q[j])
        {
            r[++k] = p[i];
            s[k] = i;
            t[k] = j;
        }
    }
    r[0] = k;
    ans = 1;
    for(int i = 1, u, v; i <= k; ++i)
    {
        u = s[i]; v = t[i];
        ll sum = 0;
        for(int j = c, l; j <= d; ++j)
        {
            l = j*g[v]/f[u];
            l = max(l, a-1);
            l = min(l, b);
            sum += 1ll*j*g[v]*(b-l)+1ll*f[u]*(a+l)*(l-a+1)/2;
            sum %= mod - 1;
        }
        (ans *= pow(r[i], sum)) %= mod;
    }
    printf("%lld", ans);
    return 0;
}