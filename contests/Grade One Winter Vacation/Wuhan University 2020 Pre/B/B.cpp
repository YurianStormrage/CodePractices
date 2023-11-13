#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}

const int N = (int)5e5 + 2;

int n, t[N];
int num[41];
ll ans;

int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) t[i] = read();
    for(int i = n; i >= 1; --i)
    {
        ans += num[-t[i]+20];
        num[t[i]+20]++;
    }
    printf("%lld", ans);
    return 0;
}