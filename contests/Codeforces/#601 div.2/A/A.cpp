#include <cstdio>

typedef long long ll;

int q, a, b;
int d, ans;

inline ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}

int main()
{
    q = read();
    while(q--)
    {
        a = read(); b = read();
        d = a-b;
        if(d < 0) d = -d;
        ans += d/5; d %= 5;
        ans += d>>1; d %= 2;
        ans += d;
        printf("%d\n",ans);
        ans = 0;
    }
    return 0;
}