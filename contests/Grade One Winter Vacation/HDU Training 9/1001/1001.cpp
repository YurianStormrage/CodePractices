#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)5e5+2, M = N << 1;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? -x : x;
}
int n;
int hd[N], nxt[M], to[N], tot;
inline void addedge(const int& u, const int& v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
}
int sz[N];
ll tmp, ans, sum;
inline void dfs(int u, int fa)
{
    sz[u] = 1;
    for(int i = hd[u], v; i; i = nxt[i])
    {
        v = to[i];
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
inline void dfs_2(int u, int fa)
{
    tmp += sz[1] - sz[u];
    ans = max(ans, tmp);
    //printf("%d : %lld\n", u, tmp);
    for(int i = hd[u]; i; i = nxt[i])
    {
        if(to[i] == fa) continue;
        dfs_2(to[i], u);
    }
    tmp -= sz[1] - sz[u];
}
int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        tot = 0; for(int i = 1; i <= n; ++i) hd[i] = 0;
        for(int i = 2; i <= n; ++i) addedge(read(), i);
        for(int i = 1; i <= n; ++i) sz[i] = 0;
        dfs(1, 0);
        ans = tmp = sum = 0;
        for(int i = 1; i <= n; ++i) sum += sz[i];
        dfs_2(1, 0);
        printf("%lld\n", ans + sum);
    }
    return 0;
}