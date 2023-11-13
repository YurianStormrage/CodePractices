#include <cstdio>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2;
int q, n, nxt[N];
bool in[N];
int ans[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int dfs(int u, int step)
{
    in[u] = 1;
    if(!in[nxt[u]]) ans[u] = dfs(nxt[u], step+1);
    else ans[u] = step;
    return ans[u];
}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 1; i <= n; ++i) nxt[i] = read(), in[i] = 0;
        for(int i = 1; i <= n; ++i) if(!in[i]) dfs(i, 1);
        for(int i = 1; i <= n; ++i) printf("%d ",ans[i]); printf("\n");
    }
    return 0;
}