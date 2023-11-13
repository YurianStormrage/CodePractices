#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = (int)2e5+2;

inline int Min(int a, int b) {return a < b? a : b;}
inline int Max(int a, int b) {return a > b? a : b;}

int n, m;
int a[N];
ll sum[N], ans[N];

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i) sum[i] = sum[i-1]+a[i];
    for(int i = 1; i <= m; ++i) ans[i] = sum[i];
    for(int i = m+1; i <= n; ++i) ans[i] = ans[i-m]+sum[i];
    for(int i = 1; i <= n; ++i) printf("%lld ",ans[i]);
    return 0;
}