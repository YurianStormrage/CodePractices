#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cassert>


using namespace std;
typedef long long ll;
const int mod = (int)1e9+7;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

ll bruteSolution(ll n, ll k)
{
    ll ans = n % mod;
    auto logN = log(n);
    for (ll kk = 2; kk <= k; ++ kk)
    {
        ll tmp = ((n - 1) / kk + 1) % mod, div = 0;
        if (kk < n) div = ll(logN / log(kk)) % mod;
        else if (kk == n) div = 1;
        ans = (ans + tmp + div) % mod;
    }
    return ans;
}

ll sumNDivK(ll n, ll k)
{
    ll ans = 0;
    while (k)
    {
        auto div = n / k;
        auto kk = n / (div + 1);
        ans = (ans + (k - kk) * div % mod) % mod;
        k = kk;
    }
    return ans;
}
ll sumNDivK_up(ll n, ll k)
{
    ll ans = 0;
    if(k > n)
    {
        ans = (k - n) % mod;
        k = n;
    }
    while (k)
    {
        auto div = n / k;
        auto kk = n / (div + 1);
        ans = (ans + (k - kk) * (div + (n % k != 0)) % mod) % mod;
        k = kk;
    }
    return ans;
}
ll sumLog_kN(ll n, ll k)
{
    ll ans = 0, kk = min(n, k);
    auto logN = log(n);
    while (kk > 1)
    {
        auto logK = log(kk);
        ll div = logN / logK;
        ll nxt = pow(n, 1.0 / (div + 1.0));
        ans = (ans + (kk - nxt) * div % mod) % mod;
        kk = nxt;
    }
    return ans;
}



int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n, k;
    n = read(); k = read();
    auto ans = (sumNDivK(n - 1, k) + k + sumLog_kN(n, k)) % mod;
    cout << ans << endl;
    //assert(ans == bruteSolution(n, k));
    //cerr << '(' << n << ", " << k << "): Passed assertion.\n";

    return 0;
}