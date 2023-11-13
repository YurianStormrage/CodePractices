#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)5e5+2;

int q, n, k;
int hd[N], nxt[N<<1], to[N<<1], val[N<<1], tot;
ll f[N], g[N];
int tmp[N];

inline bool cmp(int a, int b) {return a > b;}

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

inline void addedge(int u, int v, int w)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; val[tot] = w;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u; val[tot] = w;
}

void dfs(int u, int fa)
{
    for(int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if(v != fa) dfs(v, u);
    }
    tmp[0] = 0;
    ll sum = 0;
    for(int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if(v == fa) continue;
        tmp[++tmp[0]] = f[v] + val[i] - g[v];
        sum += g[v];
    }
    sort(tmp+1, tmp+1+tmp[0], cmp);
    g[u] = f[u] = sum;
    for(int i = 1; i <= k && i <= tmp[0]; ++i)
    {
        if(tmp[i] <= 0) break;
        g[u] += tmp[i];
        if(i < k) f[u] += tmp[i];
    }
}

int main()
{
//    q = read();
    scanf("%d",&q);
    while(q--)
    {
//        n = read(); k = read();
        scanf("%d%d",&n,&k);
        tot = 0; for(int i = 1; i <= n; ++i) hd[i] = 0;
//        for(int i = 1; i < n; ++i) addedge(read(), read(), read());
        int u, v, w;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u, v, w);
        }
        dfs(1, 0);
        printf("%lld\n",g[1]);
    }
    return 0;
}