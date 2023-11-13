#include <cstdio>
#include <algorithm>
using namespace std;
const int N = (int)1e5+1;
typedef long long ll;
int n;
ll k;
int a[N];
int ans;

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    n = read(); k = read();
    for(int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    
    sort(a+1, a+n+1);

    ans = a[n] - a[1];
    int l = 1, r = n;
    while(a[l] < a[r])
    {
        while(a[l] == a[l+1]) ++l;
        while(a[r] == a[r-1]) --r;
        ll tmpl = (ll) l*(a[l+1]-a[l]), tmpr = (ll) (n-r+1)*(a[r]-a[r-1]);
        if(l <= n-r+1)
        {
            if(k >= tmpl)
            {
                k -= tmpl;
                ++l;
                ans = a[r] - a[l];
            }
            else if(k >= l)
            {
                ans -= k/l;
                break;
            }
            else break;
        }
        else
        {
            if(k >= tmpr)
            {
                k -= tmpr;
                --r;
                ans = a[r] - a[l];
            }
            else if(k >= n-r+1)
            {
                ans -= k/(n-r+1);
                break;
            }
            else break;
        }
    }
    printf("%d",ans);
    return 0;
}