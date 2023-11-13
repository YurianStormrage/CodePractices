#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)2e4 + 2, M = (int)5e4 + 2;
int n, m;
int low[N], dfn[N], inx;
int in[N], out[N];
int hd[N], nxt[M], to[M], tot;
int cnt, node[N];
int ans1, ans2;
inline void addedge(int u, int v) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;}
inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int stk[N], tp;
bool ins[N];
void tarjan(int u)
{
    tp = 0;
    stk[tp++] = u;
    low[u] = dfn[u] = ++inx;
    int v;
    for(int i = hd[u]; i; i = nxt[i])
    {
        v = to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == dfn[u])
    {
        ++cnt;
        while(1)
        {
            v = stk[--tp];
            ins[v] = 0;
            node[v] = cnt;
            if(u == v) return;
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        tot = inx = 0;
        cnt = ans1 = ans2 = 0;
        for(int i = 1; i <= n; ++i) hd[i] = dfn[i] = in[i] = out[i] = 0;
        for(int i = 1; i <= m; ++i) addedge(rea(), rea());
        for(int i = 1; i <= n; ++i)
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(cnt == 1) {puts("0"); continue;}
        int u, v;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = hd[i]; j; j = nxt[j])
            {    
                u = node[i]; v = node[to[j]];
                if(u != v)
                {
                    out[u]++;
                    in[v]++;
                }
            }
        }
        for(int i = 1; i <= cnt; ++i)
        {
            ans1 += (in[i] == 0);
            ans2 += (out[i] == 0);
        }
        printf("%d\n", max(ans1, ans2));
    }
    return 0;
}