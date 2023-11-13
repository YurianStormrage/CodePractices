#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)5e2 + 2, M = (int)1e3 + 2;
int k, n, m;
int hd[N], nxt[M], to[M], tot;
bool vis[N];
int mch[N], ans;
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
}
int rea()
{
    int x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
bool findMatch(int u)
{
    int v;
    for(int i = hd[u]; i; i = nxt[i])
    {
        v = to[i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(!mch[v] || findMatch(mch[v]))
        {
            mch[v] = u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    while((k = rea()) != 0)
    {
        n = rea(); m = rea();
        for(int i = 1; i <= n; ++i) hd[i] = 0;
        //memset(hd, 0, sizeof(hd));
        //memset(nxt, 0, sizeof(nxt));
        //memset(to, 0, sizeof(to));
        //memset(mch, 0, sizeof(mch));
        for(int i = 1; i <= m; ++i) mch[i] = 0;
        tot = 0;
        for(int i = 1; i <= k; ++i)
        {
            int u, v;
            u = rea(); v = rea();
            addedge(u, v);
        }
        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            //if(mch[i]) continue;
            memset(vis, 0, sizeof(vis));
            if(findMatch(i)) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}