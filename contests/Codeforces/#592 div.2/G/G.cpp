#include <cstdio>
typedef long long ll;
const int N = (int)1e6+5;
int n;
ll k, Ans;
int ans[N];
bool inq[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); k = read();
    Ans = (ll)n*(n+1)>>1;
    if(Ans > k) {printf("-1"); return 0;}
    else if(Ans == k)
    {
        printf("%lld\n",Ans);
        for(int j = 1; j <= 2; ++j)
        {
            for(int i = 1; i <= n; ++i) printf("%d ",i);
            printf("\n");
        }
        return 0;
    }
    int tmp = n;
    for(int i = 1; i <= n; ++i)
    {
        while(tmp > i)
        {
            if((ll) Ans + tmp-i <= k)
            {
                Ans += tmp-i;
                inq[ans[i] = tmp] = 1;
                if(tmp < n && !inq[tmp+1]) ++tmp;
                else while(inq[--tmp]);
                break;
            }
            else while(inq[--tmp]);
        }
    }
    printf("%lld\n",Ans);
    for(int i = 1; i <= n; ++i) printf("%d ",i); printf("\n");
    int l = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(ans[i]) printf("%d ",ans[i]);
        else
        {
            while(inq[++l]);
            printf("%d ",l);
        }
    }
    return 0;
}