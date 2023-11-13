#include <cstdio>
typedef long long ll;
const int N = (int)2e3 + 2;
int n, k;
int a[N];
inline int abs(int x) {return x > 0? x : -x;}
ll rea()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for (; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? -x : x;
}
bool check(int mid)
{
    int cnt = k;
    int now = 1;
    bool flag = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(flag)
        {
            if(abs(a[i]-a[i-1]) > mid)
            {
                now = i-1;
                cnt--;
                flag = 0;
            }
        }
        else
        {
            if((abs(a[i]-a[now])+1)>>1 <= mid)
            {
                flag = 1;
                now = i;
            }
            else cnt--;
        }
    }
    return cnt >= 0;
}
int main()
{
    n = rea(); k = rea();
    int l = 0, r;
    for(int i = 1; i <= n; ++i) a[i] = rea();
    for(int i = 2; i <= n; ++i) if(r < abs(a[i]-a[i-1])) r = abs(a[i]-a[i-1]);
    int mid, ans = -1;
    while(l <= r)
    {
        mid = (l+r)>>1;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}