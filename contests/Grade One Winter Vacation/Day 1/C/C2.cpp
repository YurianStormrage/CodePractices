#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)2e3 + 2, M = N*N>>1;
int n, k;
int a[N];
int s[N][N];
int map[M];
inline bool cmp(int a, int b) {return a < b;}
inline int abs(int x) {return x > 0? x : -x;}
inline int max(int a, int b) {return a > b ? a : b;}
ll rea()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for (; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? -x : x;
}
bool check(int mid)
{
    int dis[N];
    for(int i = n; i >= 1; --i)
    {
        dis[i] = 1;
        for(int j = i+1; j <= n; ++j)
            if(s[i][j] <= mid) dis[i] = max(dis[j] + 1, dis[i]);
    }
    for(int i = 1; i <= n; ++i) if(dis[i] >= n-k) return 1;
    return 0;
}
int main()
{
    n = rea(); k = rea();
    for(int i = 1; i <= n; ++i) a[i] = rea();
    for(int i = 1; i < n; ++i)
    {
        s[i][i+1] = abs(a[i] - a[i+1]);
        map[++map[0]] = s[i][i+1];
        for(int j = i+2; j <= n; ++j)
        {
            s[i][j] = abs(a[i] - a[j])/(j-i) + (abs(a[i] - a[j]) % (j-i) != 0);
            map[++map[0]] = s[i][j];
        }
    }
    map[++map[0]] = 0;
    sort(map+1, map+1+map[0], cmp);
    int l = 1, r = map[0], mid, ans = 0;
    while(l <= r)
    {
        mid = (l+r)>>1;
        if(check(map[mid]))
        {
            ans = map[mid];
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}