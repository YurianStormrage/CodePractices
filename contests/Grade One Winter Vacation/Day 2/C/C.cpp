#include <cstdio>
typedef long long ll;
const int N = (int)1e5 + 2, inf = (int)1e8;
int n, c;
int f[2][101];
int a[N];
int ans;
inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int abs(int x) {return x > 0? x : -x;}
ll rea()
{
    ll x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    n = rea(); c = rea();
    int maxh = 0;
    for(int i = 1; i <= n; ++i)
    {
        a[i] = rea();
        maxh = max(a[i], maxh);
    }

    for(int i = 1; i <= maxh; ++i) f[0][i] = f[1][i] = inf;
    int p = 0;
    for(int i = a[1]; i <= maxh; ++i) f[p][i] = (i - a[1]) * (i - a[1]);
    for(int i = 2; i <= n; ++i)
    {
        p ^= 1;
        int tmp = inf;
        for(int j = a[i-1]; j < a[i]; ++j) tmp = min(f[p ^ 1][j] - j * c, tmp);
        for(int j = a[i]; j <= maxh; ++j)
        {
            tmp = min(f[p ^ 1][j] - j * c, tmp);
            f[p][j] = tmp + j * c + (j - a[i]) * (j - a[i]);
        }
        tmp = inf;
        for(int j = maxh; j >= a[i]; --j)
        {
            tmp = min(f[p ^ 1][j] + j * c, tmp);
            f[p][j] = min(tmp - j * c + (j - a[i]) * (j - a[i]), f[p][j]);
        }
        for(int j = a[i-1]; j <= maxh; ++j) f[p ^ 1][j] = inf;
    }

    ans = inf;
    for(int i = a[n]; i <= maxh; ++i) ans = min(f[p][i], ans);
    printf("%d", ans);
    return 0;
}