#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = (int)1e5 + 2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}
int n, k;
int a[N], f[N];
int mid;
inline int abs(int x) {return x > 0? x : -x;}
int dfs(int u)
{
    if(f[u]) return f[u];
    int res = 1;
    for(int i = u+1; i <= u+10000; ++i)
    {
        if((double)abs(a[u] - a[i])/(i-u) <= mid)
        {
            int tmp = 1 + dfs(i);
            if(tmp > res) res = tmp;
        }
    }
    return f[u] = res;
}
bool check()
{
    for(int i = 1; i <= n; ++i) f[i] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dfs(i) >= n-k) return 1;
    }
    return 0;
}
int main()
{
    freopen("test.in", "r", stdin);
    n = read(); k = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    int l, r;
    l = r = a[1];
    for(int i = 2; i <= n; ++i)
    {
        if(a[i] < l) l = a[i];
        if(a[i] > r) r = a[i];
    }
    r = r-l; l = 0;
    int ans = -1;
    while(l <= r)
    {
        mid = (l+r)>>1;
        if(check())
        {
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    printf("%d", ans);
    return 0;
}