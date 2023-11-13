#include <cstdio>
typedef long long ll;
const int N = (int)2e5+2;
int q, n, m;
int a[N], p[N], s[N], maxP[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline int Max(int a, int b){return a>b?a:b;}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        m = read();
        int maxS = 0;
        for(int i = 1; i <= m; ++i)
        {
            p[i] = read(); s[i] = read();
            maxS = Max(s[i], maxS);
        }
        for(int i = 1; i <= m; ++i) maxP[s[i]] = Max(p[i], maxP[s[i]]);
        for(int i = maxS-1; i; --i) maxP[i] = Max(maxP[i+1],maxP[i]);
        int pos = 0, ans = 0;
        while(pos < n)
        {
            if(a[pos+1] > maxP[1]) break;
            int tmp = 1, mx = a[pos+1];
            while(tmp <= maxS && maxP[tmp] >= mx)
            {
                ++tmp;
                mx = Max(a[pos+tmp], mx);
            }
            pos += tmp-1;
            ++ans;
        }
        if(pos < n) puts("-1");
        else printf("%d\n",ans);
        for(int i = 1; i <= maxS; ++i) maxP[i] = 0;
    }
    return 0;
}