#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)5e2 + 2;
int k, n, m;
int link[N][N];
bool vis[N];
int mch[N], ans;
ll rea()
{
    ll x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
bool findMatch(int u)
{
    for(int i = 1; i <= m; ++i)
    {
        if(!link[u][i] || vis[i]) continue;
        vis[i] = 1;
        if(!mch[i] || findMatch(mch[i]))
        {
            mch[i] = u;
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
        memset(mch, 0, sizeof(mch));
        memset(link, 0, sizeof(link));
        for(int i = 1; i <= k; ++i) link[rea()][rea()] = 1;
        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(findMatch(i)) ++ans;
            memset(vis, 0, sizeof(vis));
        }
        printf("%d\n", ans);
    }
    return 0;
}