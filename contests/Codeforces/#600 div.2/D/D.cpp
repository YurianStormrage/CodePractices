#include <cstdio>

typedef long long ll;
const int N = (int)2e5+2;

inline int Min(int a, int b) {return a < b? a : b;}
inline int Max(int a, int b) {return a > b? a : b;}

int n, m;
int hd[N], nxt[N<<1], to[N<<1], tot;
bool vis[N];
int r, ans;
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

void dfs(int u)
{
    vis[u] = 1;
    r = Max(u, r);
    int v;
    for(int i = hd[u]; i; i = nxt[i])
    {
        v = to[i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    n = read(); m = read();
    for(int i = 0; i < m; ++i) addedge(read(), read());
    int R = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
        {
            r = 0;
            dfs(i);
            if(i < R) ++ans;
            R = Max(r, R);
        }
    printf("%d", ans);
    return 0;
}