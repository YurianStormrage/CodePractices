#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 52;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int n, k;
ll ans;
struct item
{
    item() {}
    item(int A, int B, int C, int D):a(A), b(B), c(C), d(D) {}
    int a, b, c, d;
} it[N][N];
struct pair
{
    int a, b;
    inline bool operator <(pair x)
    {
        return a < x.a;
    }
}cnt[N];

void dfs(int step, int a, int b, int c, int d)
{
    if(step > k)
    {
        ll tmp = (ll)(100+a)*(100+b)*(100+c)*(100+d);
        if(tmp > ans) ans = tmp;
        return ;
    }
    for(int i = 1; i <= cnt[step].a; ++i)
        dfs(step+1, a+it[cnt[step].b][i].a, b+it[cnt[step].b][i].b, c+it[cnt[step].b][i].c, d+it[cnt[step].b][i].d);
    if(!cnt[step].a) dfs(step+1, a, b, c, d);
    return ;
}

int main()
{
    int T = read();
    while(T--)
    {
        n = read(); k = read();
        for(int i = 1; i <= k; ++i) cnt[i].a = 0, cnt[i].b = i;
        for(int i = 1, t, a, b, c, d; i <= n; ++i)
        {
            t = read();
            a = read(); b = read(); c = read(); d = read();
            it[t][++cnt[t].a] = item(a, b, c, d);
        }
        sort(cnt+1, cnt+1+k);
        ans = 0;
        dfs(1, 0, 0, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}