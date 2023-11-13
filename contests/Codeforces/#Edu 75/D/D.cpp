#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Max(a, b) ((a)>(b)? (a):(b))
const int N = (int)2e5+2;
int q, n;
ll s, mid;
struct People{int l, r;}p[N];
int que[N], t;
inline bool cmp(const People& a, const People& b) {return a.l < b.l;}
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline void Debug()
{
    printf("mid = %d\n",mid);
    for(int i = 0; i < n; ++i) printf("l = %d r = %d\n",p[i].l, p[i].r); printf("\n");
}
inline bool check()
{
    int num = 0;
    ll tmp = 0;
    t = 0;
    for(int i = 0; i < n; ++i)
        if(p[i].r < mid) tmp += p[i].l;
        else if(p[i].l >= mid) {tmp += p[i].l; ++num;}
        else que[t++] = i;
    int d = Max(((n+1)>>1)-num, 0);
    if(d > t) return false;
    int i = 0, lim = t-d;
    for(; i < lim; ++i) tmp += p[que[i]].l;
    for(; i < t; ++i) tmp += mid;
    return tmp <= s;
}
int main()
{
    freopen("D.in","r",stdin);
    q = read();
    while(q--)
    {
        n = read(); s = read();
        for(int i = 0; i < n; ++i) p[i].l = read(), p[i].r = read();
        ll L, R = s, ans;
        sort(p, p+n, cmp); L = p[n>>1].l;
        while(L <= R)
        {
            mid = (L+R)>>1;
            if(check())
            {
                L = mid+1;
                ans = mid;
            }
            else R = mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}