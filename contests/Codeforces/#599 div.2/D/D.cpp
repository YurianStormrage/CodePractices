#include <cstdio>
typedef long long ll;
const int N = (int)1e5+2;
int n, m;
int hd[N], nxt[N<<1], to[N<<1], tot;
int l[N], r[N];
bool vis[N], link[N];
int que[N], qh, qt;
int ans;
inline void addedge(int u, int v)
{
    nxt[hd[u]] = ++tot; hd[u] = tot; to[tot] = v;
    nxt[hd[v]] = ++tot; hd[v] = tot; to[tot] = u;
}
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline void del(int x)
{
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}
int main()
{
    n = read(); m = read();
    if(!m) {putchar('0'); return 0;}
    for(int i = 1; i <= m; ++i) addedge(read(), read());
    for(int i = 1; i <= n; ++i) l[i] = i-1, r[i] = i+1;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
        {
            qh = 0;
            que[qt++] = i;
            vis[i] = 1;
            del(i);
            ++ans;
            while(qh != qt)
            {
                int p = que[qh++];
                for(int i = l[0]; i <= n; i = r[i]) link[i] = 0;
                for(int i = hd[p]; i; i = nxt[i]) link[to[i]] = 1;
                for(int i = l[0]; i <= n; i = r[i]) if(!link[i]) que[qt++] = i, del(i), vis[i] = 1;
            }
        }
    printf("%d",ans-1);
    return 0;
}