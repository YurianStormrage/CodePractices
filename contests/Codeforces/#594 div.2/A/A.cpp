#include <cstdio>
typedef long long ll;
int q, n, odd, even;
ll ans;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        odd = even = 0;
        while(n--)
            if(read()&1) ++odd;
            else ++even;
        ans = 0;
        n = read();
        while(n--)
            if(read()&1) ans += odd;
            else ans += even;
        printf("%lld\n",ans);
    }
    return 0;
}