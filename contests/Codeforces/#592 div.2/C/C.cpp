#include <cstdio>
typedef long long ll;

ll n, p;
int d, w;

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

inline int gcd(int a, int b) {return !b? a : gcd(b, a%b);}

int main()
{
    n = read(); p = read(); w = read(); d = read();

    if(!(p%gcd(w, d)))
    {
        for(int y = 0; y < w; ++y)
        {
            if((ll)p-y*d >= 0 && !((p-(ll)y*d)%w))
            {
                ll x = (ll) (p-y*d)/w;
                if(x + y <= n)
                {
                    printf("%lld %d %lld",x, y, n - x - y);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}