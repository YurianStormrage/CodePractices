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

const int N = (int)2e5+2;
const int mod = 998244353;

int n;
ll num[N];
 
ll inverse(ll x, ll y)
{
    ll res = 1;
 
    while(y)
    {
        if(y&1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res % mod;
}
 
 
int main()
{
    int n = read();
 
    num[0] = num[1] = 1;

    for(int i = 2; i <= n; ++i)
        num[i] = ((6*i-3)*num[i-1]%mod-(i-2)*num[i-2]%mod+mod)%mod*inverse(i+1,mod-2)%mod;
        
    printf("%lld\n",num[n]*2%mod);
    return 0;
}