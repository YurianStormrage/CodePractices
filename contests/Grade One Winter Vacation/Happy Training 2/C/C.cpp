#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' &&  ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) +(ch^48);
    if(f) return -x;
    return x;
}
int x, y;
int n;
double ans;
int main()
{
    x = read(); y = read();
    n = read();
    int t = y;
    int l, u;
    double f, sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        l = read(); u = read();
        scanf("%lf", &f);
        t -= u - l;
        sum += (u - l) * f;
    }
    sum += t;
    printf("%.11lf", (double)x/sum);
    return 0;
}