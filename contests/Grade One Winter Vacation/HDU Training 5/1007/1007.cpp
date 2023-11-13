#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2, M = N<<1;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n, k;
int tot, hd[N], nxt[M], to[M], d[M];
inline void addedge(int u, int v, int w)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; d[tot] = w;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u; d[tot] = w;
}

ll f[N][2];
pair<ll, ll>son[N];
ll ans;

int sz;
void dfs(int u, int fa)
{
    for(int i = hd[u]; i; i = nxt[i])
    {
        if(to[i] == fa) continue;
        dfs(to[i], u);
    }
    sz = 0;
    for(int i = hd[u], v; i; i = nxt[i])
    {
        v = to[i];
        if(v == fa) continue;
        son[++sz].first = f[v][0] + d[i];
        son[sz].second = f[v][1] + d[i];
    }
    sort(son+1, son+1+sz);
    int K = k-1;
    ll tmp = 0;
    
    for (int i = 1, lim = min(K, sz); i <= lim; ++i) tmp += son[i].first;
    f[u][0] = tmp;
    for (int i = 1, lim = min(K, sz); i <= lim; ++i) f[u][1] = max(f[u][1], tmp-son[i].first+son[i].second);
    for(int i = k; i <= sz; ++i) f[u][1] = max(f[u][1], tmp-son[K].first+son[i].second);
    for (int i = k; i <= sz; i++) tmp += son[i].first;
    f[u][1] = max(f[u][1], tmp);

    tmp = 0;
    for (int i = 1, lim = min(k, sz); i <= lim; ++i) tmp += son[i].first;
    ans = max(tmp, ans);
    for (int i = 1, lim = min(k, sz); i <= lim; ++i) ans = max(ans, tmp-son[i].first+son[i].second);
    for (int i = k+1; i <= sz; i++) ans = max(ans, tmp-son[k].first+son[i].second);
    for (int i = k+1; i <= sz; i++) tmp += son[i].first;
    ans = max(ans, tmp);
}

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); k = read();
        tot = 0;
        for(int i = 1; i <= n; ++i) hd[i] = 0;
        for(int i = 1, u, v, w; i < n; ++i)
        {
            u = read(); v = read(); w = read();
            addedge(u, v, w);
        }
        if(k == 0) {printf("0\n"); continue;}
        for(int i = 1; i <= n; ++i) f[i][0] = f[i][1] = 0;
        ans = 0;
        dfs(1, 0);
        for (int i = 1; i <= n; i++) ans = max(ans, max(f[i][0], f[i][1]));
        printf("%lld\n", ans);
    }
    return 0;
}