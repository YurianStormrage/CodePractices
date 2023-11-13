#include <cstdio>
#include <algorithm>
#define Min(a, b) ((a)<(b)? (a):(b))
using namespace std;
typedef long long ll;
const int N = (int)1e3+2, M = (int)1e3+2;
int n, m, d, c[M];
int sum[M], ans[N];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); m = read(); d = read();
    for(int i = 1; i <= m; ++i) c[i] = read();
    for(int i = m; i >= 1; --i) sum[i] = sum[i+1]+c[i];
    int pos = 0, now = 0;
    while(++now <= m && pos + (d<<1) + sum[now] - 1 <= n)
    {
        pos += d;
        for(int i = pos+c[now]-1; i >= pos; --i) ans[i] = now;
        pos += c[now]-1;
    }
    pos += d+sum[now]-1;
    if(now > m || pos + d <= n) {printf("NO"); return 0;}
    for(int lim = Min(n, pos)-sum[now]+1; now <= m; ++now)
        while(c[now]--)
            ans[lim++] = now;
    puts("YES");
    for(int i = 1; i <= n; ++i) printf("%d ",ans[i]);
    return 0;
}