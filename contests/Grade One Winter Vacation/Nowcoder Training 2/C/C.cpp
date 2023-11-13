#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2;
inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n;
int tot, to[N<<1], hd[N], nxt[N<<1];
inline void addedge(int u, int v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
    nxt[++tot] = hd[v]; hd[v] = tot; to[tot] = u;
}
int root, leaf[N], cnt;
void dfs(int u, int fa)
{
    if(!nxt[hd[u]]) leaf[cnt++] = u;
    int v;
    for(int i = hd[u]; i; i = nxt[i])
    {
        v = to[i];
        if(v == fa) continue;
        dfs(v, u);
    }
}
int main()
{
    n = read();
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        u = read(); v = read();
        addedge(u, v);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(nxt[hd[i]])
        {
            root = i;
            break;
        }
    }
    dfs(root, 0);
    printf("%d\n", (cnt+1)>>1);
    for(int i = (cnt>>1)-1; i >= 0; --i) printf("%d %d\n", leaf[cnt-1-i], leaf[i]);
    if(cnt&1) printf("%d %d\n", leaf[cnt-1], leaf[cnt>>1]);
    return 0;
}