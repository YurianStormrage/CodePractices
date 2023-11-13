#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)2e5+10;
#define Min(a, b) a < b ? a : b
     
int q;
int n, x, a, y, b, p[N];
ll k;
bool que[N];
     
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
    return x;
}
     
inline bool cmp(int a, int b) {return a > b;}

inline int gcd(int a, int b) {return !b? a:gcd(b,a%b);}
     
bool check(int mid)
{
    int used = 0, X, Y;
    ll tmp = (ll)a*b/gcd(a, b), pos = tmp, ans = 0;
    for(int i = 1; i <= mid; ++i) que[i] = false;
    while(pos <= mid)
    {
        ans += p[++used]*(x+y);
        que[pos] = true;
        pos += tmp;
    }
     
    if(x == y) tmp = Min(a, b);
    else if (x > y) tmp = a;
    else tmp = b;
    if(tmp == a) X = x, Y = y;
    else X = y, Y = x;
     
    pos = tmp;
    while(pos <= mid)
    {
        if(!que[pos])
        {
            ans += p[++used]*X;
            que[pos] = true;
        }
        pos += tmp;
    }
     
    tmp = tmp == a? b:a;
    pos = tmp;
    while(pos <= mid)
    {
        if(!que[pos]) ans += p[++used]*Y;
        pos += tmp;
    }
     
    return ans >= k;
}
     
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 1; i <= n; ++i) p[i] = read()/100;
        sort(p+1, p+n+1, cmp);
        x = read(); a = read();
        y = read(); b = read();
        scanf("%lld",&k);
 
        int l = Min(a, b), r = n, mid, ans = 0;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if(check(mid)) {r = mid - 1; ans = mid;}
            else l = mid + 1;
        }
     
        if(!ans) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}