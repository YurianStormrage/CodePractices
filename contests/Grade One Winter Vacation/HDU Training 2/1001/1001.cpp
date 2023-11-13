#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2, M = (int)2e5+2;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int n, m;
struct pair
{
    int a, b;
    inline bool operator < (pair x) {return a == x.a? b < x.b : a < x.a;}
    inline bool operator == (pair x) {return a == x.a && b == x.b;}
}b[N], edge[M];
int map[N];

int hd[N], nxt[M<<1], to[M<<1], tot;
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}

int fa[N];
int stk[N], top, num, now;
int vis[N];

inline int find(int x) {return fa[x] == x? x : fa[x] = find(fa[x]);}

void dfs(int u, int inx)
{
    vis[u] = inx;
    for(int i = hd[u], v; i; i = nxt[i])
    {
        v = to[i];
        if(vis[v] == inx) continue;
        if(find(u) == find(v)) dfs(v, inx);
        else if(b[map[v]].a == now)
        {
            //stk[++top] = map[v];
            fa[find(v)] = find(u);
            dfs(v, inx);
        }
        else
        {
            if(num < b[map[v]].a)
            {
                num = b[map[v]].a;
                stk[top = 1] = v;
            }
            else if(num == b[map[v]].a) stk[++top] = v;
        }
    }
}

int main()
{
    //freopen("1001.in", "r", stdin);
    for(int T = read(); T--;)
    {
        n = read(); m = read();
        for(int i = 1; i <= n; ++i) 
        {
            b[i].a = read(), b[i].b = i;
        }
        sort(b+1, b+1+n);
        for(int i = 1; i <= n; ++i) map[b[i].b] = i, vis[i] = 0;
        for(int i = 1; i <= n; ++i) fa[i] = i;
        tot = 0;
        for(int i = 1; i <= n; ++i) hd[i] = 0;
        for(int i = 1, u, v; i <= m; ++i)
        {
            u = read(); v = read();
            if(u > v) swap(u, v);
            edge[i].a = u, edge[i].b = v;
        }
        sort(edge+1, edge+1+m);
        addedge(edge[1].a, edge[1].b);
        for(int i = 2; i <= m; ++i)
        {
            if(edge[i] == edge[i-1]) continue;
            addedge(edge[i].a, edge[i].b);
        }

        ll ans = 0;
        for(int i = n, u, tp; i >= 1; --i)
        {
            u = b[i].b;
            if(find(u) != u) continue;
            num = 0; now = b[i].a;
            dfs(u, i);
            ans += now - num;
            if(top)
            {
                tp = stk[top--];
                while(top) fa[find(stk[top--])] = find(tp);
                fa[find(u)] = find(tp);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}