#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n;
int fa[N];
int num[N][2];
inline int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        for(int i = 0; i <= n; ++i) num[i][0] = num[i][1] = 0;
        for(int i = 1, p; i <= n; ++i)
        {
            fa[i] = i;
            p = read() - 1;
            num[i][p]++;
            num[0][p]++;
        }
        //for(int i = 0; i <= n; ++i) printf("%d %d\n", num[i][0], num[i][1]);
        ll ans = ((ll)num[0][0]*num[0][1]*(num[0][1]-1)/2%mod+(ll)num[0][1]*(num[0][1]-1)*(num[0][1]-2)/6%mod)%mod;
        printf("%lld\n", ans);
        for(int i = 1, u, v; i < n; ++i)
        {
            u = find(read()); v = find(read());
            ll tmp = (ll)num[u][1]*num[v][1]%mod*(n-num[u][0]-num[u][1]-num[v][0]-num[v][1])%mod;
            tmp = (tmp + (ll)num[u][0]*num[v][1]%mod*(num[0][1]-num[u][1]-num[v][1])%mod)%mod;
            tmp = (tmp + (ll)num[u][1]*num[v][0]%mod*(num[0][1]-num[u][1]-num[v][1])%mod)%mod;
            ans = (ans + mod - tmp) % mod;
            printf("%lld\n", ans);
            fa[v] = u;
            num[u][0] += num[v][0];
            num[u][1] += num[v][1];
        }
    }
    return 0;
}