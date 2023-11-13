#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch-48);
    if(f) return -x;
    return x;
}

const int mod = (int)1e9+7;

int n, m;

ll pow(int x)
{
    ll res = 1, tmp = 2;
    while(x)
    {
        if(x&1) res = res * tmp % mod;
        tmp = tmp * tmp % mod;
        x >>= 1;
    }
    return res;
}

int main()
{
    int q = read();
    while(q--)
    {
        n = read(); m = read();
        printf("%lld\n", pow(n-1)*m%mod);
    }
    return 0;
}