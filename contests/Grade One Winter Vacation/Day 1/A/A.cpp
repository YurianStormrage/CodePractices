#include <cstdio>
typedef long long ll;
const int N = (int)1e3 + 2;
int n, d[N];
int que[N], qh, qt, inx;
ll rea()
{
    ll x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = rea();
    for(int i = 1; i <= n; ++i) d[i] = rea();
    que[qt++] = 1; inx = 2;
    int p;
    while(qh < qt && inx <= n)
    {
        p = que[qh];
        while(d[p] && inx <= n)
        {
            d[p]--;
            if(--d[inx]) que[qt++] = inx;
            inx++;
        }
        if(d[p]) break;
        qh++;
    }
    if(qh == qt && inx > n) printf("YES");
    else printf("NO");
    return 0;
}