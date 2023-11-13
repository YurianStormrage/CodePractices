#include <cstdio>
#include <cmath>
typedef long long ll;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    ll n, f = 0;
    n = read();
    int lim = sqrt(n);
    for(int i = 2; i <= lim; ++i) if(!(n%i)) {f = i; break;}
    if(!f) {printf("%lld",n); return 0;}
    int tmp = f;
    while(n > (f*=f));
    while(f != 1)
    {
        while(!(n%f)) n /= f;
        f = sqrt(f);
    }
    if(n == 1) printf("%d",tmp);
    else putchar('1');
    return 0;
}