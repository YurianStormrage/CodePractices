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

ll n;

ll pow(ll x, ll y)
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
    for(int T = read(); T--;)
    {
        n = read();
        ll a = pow(2, n);
        ll b = pow(3, n);
        ll inv_a = pow(a, (ll)mod-2);
        printf("%lld\n", (2*b%mod*inv_a%mod+a+1)%mod);
    }
    return 0;
}