#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}

const int N = 1e6 + 2, mod = 1e9 + 7;
int n, f[N];

int main()
{
    n = read();
    if(n <= 2) printf("%d", n);
    else {
    ll ans = 0;
    f[n] = f[n - 1] = 1;
    for(int i = n - 2; i > 2; --i) {
        f[i] = f[i + 1] +  1;
        for(int j = i << 1; ; j += i)
            for(int k = j; k <= j + 2; ++k) {
                if(k > n) goto _Next;
                f[i] += f[k - 1];
                if(f[i] > mod) f[i] -= mod;
            }
        _Next:;
    }
    for(int i = 3; i <= n; ++i) {
        ans += f[i];
        if(ans > mod) ans -= mod;
    }
    printf("%lld", 2LL * ans % mod * n % mod);
    }
    return 0;
}