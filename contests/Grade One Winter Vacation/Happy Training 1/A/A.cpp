#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = (int)1e5 + 2, M = (int)1e8 + 2;

inline int Max(int a, int b) {return a > b ? a : b;}
inline int Min(int a, int b) {return a < b ? a : b;}

int n, d;
struct frog
{
    int l, w, h;
}fg[N];
inline bool cmp(frog a, frog b) {return a.w > b.w;}
int f[M];

inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return x;
    return -x;
}
int main()
{
    n = read(); d = read();
    for(int i = 1; i <= n; ++i)
    {
        fg[i].l = read();
        fg[i].w = read();
        fg[i].h = read();
    }
    sort(fg+1, fg+1+n, cmp);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(fg[i].l + f[fg[i].w] > d) ++ans;
        int lim = Min(fg[i].w, M - fg[i].w);
        for(int j = 1; j < lim; ++j)
            f[j] = Max(f[j], f[j + fg[i].w] + fg[i].h);
    }
    printf("%d", ans);
    return 0;
}