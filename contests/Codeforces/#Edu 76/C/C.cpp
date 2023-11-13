#include <cstdio>
typedef long long ll;
const int N = (int)2e5+2;
int q, n, m;
int a[N], cnt[N], L[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline int Min(int a, int b){return a<b?a:b;}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        int l = 1, r = 1, ans = N;
        while(true)
        {
            while(r <= n && !cnt[a[r]]++)
            {
                L[a[r]] = r;
                r++;
            }
            if(r > n) break;
            ans = Min(r-L[a[r]]+1, ans);
            while(cnt[a[r]] > 1) --cnt[a[l++]];
            L[a[r]] = r;
            if(++r > n) break;
        }
        if(ans == N) puts("-1");
        else printf("%d\n",ans);
        for(int i = 1; i <= n; ++i) cnt[a[i]] = 0;
    }
    return 0;
}