#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' &&  ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}

const int N = (int)1e5 + 2, M = (int)1e6 + 2;
int n, m;
int tot;
int hd[N], nxt[M], to[M];
inline void addedge(int u, int v) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;}

int cnt, dfn[N], low[N], scc[N], cntscc;

int no[N], id[N][5], sz[N];
bool go[N][5][5];
int dis[N][5][5];
int f[N][5][2], ans;

int stk[N], top = -1;
void tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    stk[++top] = u;
    int v;
    for(int i = hd[u]; i; i = nxt[i])
    {
        v = to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v]) low[u] = min(low[u], low[v]);
    }

    if(low[u] == dfn[u])
    {
        ++cntscc;
        while(!scc[u])
        {
            v = stk[top--];
            scc[v] = cntscc;
            no[v] = sz[scc[v]]++;
            id[scc[v]][no[v]] = v;
        }
    }
}

bool vis[N];
void dfs(int scc, int p, int u, int ans)
{
    if(vis[u]) return;
    vis[u] = 1;
    dis[scc][p][u] = max(dis[scc][p][u], ans);
    for(int i = 0; i < sz[scc]; ++i) if(go[scc][u][i]) dfs(scc, p, i, ans + 1);
    vis[u] = 0;
}

int srch(int Scc, int u, bool t)
{
    if(~f[Scc][u][t]) return f[Scc][u][t];
    f[Scc][u][t] = 0;
    for(int i = hd[id[Scc][u]], v; i; i = nxt[i])
    {
        v = to[i];
        if(scc[id[Scc][u]] != scc[v])
            f[Scc][u][t] = max(f[Scc][u][t], srch(scc[v], no[v], 0)+1);
    }
    if(!t) for(int i = 0; i < sz[Scc]; ++i) if(dis[Scc][u][i])
        f[Scc][u][t] = max(f[Scc][u][t], srch(Scc, i, 1)+dis[Scc][u][i]);
    return f[Scc][u][t];
}

int main()
{
    n = read(); m = read();
    for(int i = 1, x, y; i <= m; ++i)
    {
        x = read(); y = read();
        addedge(x, y);
    }
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);

    for(int i = 1; i <= n; ++i)
    {
        for(int t = hd[i], v; t; t = nxt[t])
        {
            v = to[t];
            if(scc[i] == scc[v]) go[scc[i]][no[i]][no[v]] = 1;
        }
    }
    
    for(int i = 1; i <= cntscc; ++i)
        for(int j = 0; j < sz[i]; ++j)
            dfs(i, j, j, 0);
    
    memset(f, -1, sizeof(f));
    for(int i = 1; i <= n; ++i) ans = max(ans, srch(scc[i], no[i], 0));
    printf("%d", ans + 1);
    
    return 0;
}