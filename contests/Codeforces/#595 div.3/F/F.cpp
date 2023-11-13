#include <cstdio>
#define Max(a, b) ((a)>(b)? (a):(b))
typedef long long ll;
const int N = 202;
int n, k;
int hd[N], nxt[N<<1], to[N<<1], tot;
int f[N][N];
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
void dfs(int u, int fa)
{
    for(int i = hd[u]; i; i = nxt[i]) if(to[i] != fa) dfs(to[i], u);
    if(!nxt[hd[u]] && to[hd[u]] == fa) return;
    int sum[N] = {0};
    for(int j = k; j >= 0; --j)
        for(int i = hd[u]; i; i = nxt[i])
            if(to[i] != fa)
                sum[j] += f[to[i]][j];
    /*
    printf("for %d:\n",u);
    for(int i = 0; i <= k; ++i) printf("sum[%d] = %d\n",i, sum[i]);
    */
    int lim = (k+1)>>1, j;
    for(j = k; j > lim; --j)
    {
        for(int i = hd[u]; i; i = nxt[i])
            if(to[i] != fa)
                f[u][j] = Max(f[to[i]][j-1]+sum[j-1]-f[to[i]][j-1], f[u][j]);
        f[u][j] = Max(f[u][j], f[u][j+1]);
    }
    for(; j > 0; --j)
    {
        for(int i = hd[u]; i; i = nxt[i])
            if(to[i] != fa)
                f[u][j] = Max(f[to[i]][j-1]+sum[k-j]-f[to[i]][k-j], f[u][j]);
        f[u][j] = Max(f[u][j], f[u][j+1]);
    }
    f[u][0] = Max(f[u][0]+sum[k], f[u][1]);
}
int main()
{
    n = read(); k = read();
    for(int i = 1; i <= n; ++i) f[i][0] = read();
    for(int i = 1; i < n; ++i) addedge(read(), read());

    dfs(1, 0);
    /*
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            printf("f[%d][%d] = %d, g[%d][%d] = %d\n",i,j,f[i][j],i,j,g[i][j]);
    */
    printf("%d",f[1][0]);
    return 0;
}