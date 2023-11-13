#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 2;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}
inline int abs(int x) {return x > 0? x : -x;}

int n;
ll r;
struct seg
{
    int l, r;
}s[N];

inline bool cmp(seg a, seg b) {return a.r != b.r? a.r < b.r : a.l < b.l;}

int main()
{
    n = read(); r = read();
    for(int i = 1; i <= n; ++i)
    {
        ll x, y;
        x = read(); y = read();
        int tmp = sqrt(r*r-y*y);
        s[i].l = x-tmp;
        s[i].r = x+tmp;
    }
    sort(s+1, s+1+n, cmp);
    int x = s[1].r, ans = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(x < s[i].l)
        {
            ++ans;
            x = s[i].r;
        }
    }
    printf("%d", ans);
    return 0;
}