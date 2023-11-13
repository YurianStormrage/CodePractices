#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2, inf = (int)1e9;
int n;
pair<int, int> a[N];
int fa[N], f[N], ans[N];
//int Tmp, Ans, ans[N], tot;
inline bool cmp1(pair<int,int> a, pair<int,int> b){return a.first==b.first? a.second<b.second : a.first < b.first;}
//inline bool cmp2(pair<int,int> a, pair<int,int> b){return a.second<b.second;}
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
/*
int dfs(int p, int lim, int step)
{
    if(n-p+1 < 3+lim) return inf;
    if(!lim)
    {
        return f[p];
    }
    for(int i = 0; i <= lim; ++i)
    {
        int tmp = dfs(p+3+i, lim-i, step+1)+a[p+2].first-a[p].first;
    }
}
*/
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i].first = read(), a[i].second = i;
    sort(a+1, a+1+n, cmp1);
    /*
    for(int i = n-2; i >= 3; i -= 3)
        if(!((n-i+1)%3))
        {
            f[i] = f[i+2] + a[i+2].first - a[i].first;
        }
    Ans = dfs(1, n%3, 1);
    */
    for(int i = 1; i <= n; ++i) f[i] = inf;
    for(int i = 3; i <= n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int tmp = i-3-j;
            if(tmp < 0) break;
            if(f[i] > f[tmp]+a[i].first-a[tmp+1].first)
            {
                fa[i] = tmp;
                f[i] = f[tmp]+a[i].first-a[tmp+1].first;
            }
        }
    }
    printf("%d ",f[n]);
    int tot = 0;
    for(int i = n; i;)
    {
        int now = i;
        ++tot;
        while(i != fa[now]) ans[a[i--].second] = tot;
    }
    printf("%d\n",tot);
    for(int i = 1; i <= n; ++i) printf("%d ",ans[i]);
    return 0;
}