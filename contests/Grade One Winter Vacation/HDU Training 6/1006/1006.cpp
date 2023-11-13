#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2, M = (int)2e5+2, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n, m;
bool a[N];
int tot, hd[N], nxt[M<<1], to[M<<1], d[M<<1];
inline void addedge(const int& u, const int& v, const int& w)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; d[tot] = w;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u; d[tot] = w;
}

int fa[N];
inline int find(const int& x) {return x == fa[x]? x : fa[x] = find(fa[x]);}

int num[N][2];
ll ans;

inline void calc(const int& u, const int& f)
{
    ++num[u][a[u]];
    for(int i = hd[u], v; i; i = nxt[i])
    {
        v = to[i];
        if(v == f) continue;
        calc(v, u);
        num[u][0] += num[v][0];
        num[u][1] += num[v][1];
    }
}

inline void init(const int& u)
{
    ans = 0;
    for(int i = 1; i <= n; ++i) num[i][0] = num[i][1] = 0;
    calc(u, 0);
}

inline void dfs(const int& u, const int& f)
{
    for(int i = hd[u], v; i; i = nxt[i])
    {
        v = to[i];
        if(v == f) continue;
        ll L0 = num[1][0] - num[v][0], L1 = num[1][1] - num[v][1];
        (ans += 1ll * d[i] * (L0*num[v][1] + L1*num[v][0]) % mod) %= mod;
        dfs(v, u);
    }
}

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); m = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        tot = 0; for(int i = 1; i <= n; ++i) hd[i] = 0, fa[i] = i;
        for(int i = 1, u, v, w = 1; i <= m; ++i)
        {
            u = read(); v = read();
            w = (w<<1) % mod;
            if(find(u) == find(v)) continue;
            addedge(u, v, w);
            fa[find(v)] = fa[u];
        }
        init(1);
        dfs(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}