#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}

int w;
ll n;
int h[N];
ll l[N], r[N];
ll sum[N];

bool check(ll mid)
{
    for(int i = 1; i <= w+1; ++i) l[i] = 0, r[i] = w + 1;
    for(int i = 1;i <= w; ++i) if(i + mid - h[i] <= N && i + mid - h[i] >= i) l[i+mid-h[i]] = i;
    for(int i = w; i >= 1; --i) if(i - mid + h[i] >=1 && i - mid + h[i] <= i) r[i-mid+h[i]] = i;
    for(int i = 1;i <= w; ++i) l[i] = max(l[i], l[i-1]);
    for(int i = w; i >= 1; --i) r[i] = min(r[i], r[i+1]);
    for(int i = 1; i <= w; ++i)
    {
        if(r[i] == w+1 || l[i] == 0) continue;
        ll res = 0;
        res += (ll)(mid+mid-(i-l[i])+1) * (i-l[i])/2;
        res += (ll)(mid-1+mid-1-(r[i]-i-1)+1) * (r[i]-i-1)/2;
        res -= sum[r[i]-1] - sum[l[i]];
        if(res <= n) return true;
    }
    return false;
}
int main()
{
    freopen("landscape.in", "r", stdin);
    freopen("landscape.out", "w", stdout);
    w = read(); n = read();
    for(int i = 1; i <= w; ++i)
    {
        h[i] = read();
        sum[i] = sum[i-1] + h[i];
    }
    int l = 0, r = (int)2e9, mid, ans;
    for(int i = 1; i <= w; ++i) l = max(l, h[i]);
    ans = l;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    printf("%d", ans);
    return 0;
}
