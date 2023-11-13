#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e5+1;
int n, a[N];
ll l, h;
inline bool cmp(int a, int b) {return a > b;}
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n, cmp);
    int lim = (n+1)>>1;
    if(n&1)
    {
        for(int i = 1; i < lim; ++i) l += a[i], h += a[n-i+1];
        l += a[lim];
    }
    else for(int i = 1; i <= lim; ++i) l += a[i], h += a[n-i+1];
    printf("%lld",l*l+h*h);
    return 0;
}