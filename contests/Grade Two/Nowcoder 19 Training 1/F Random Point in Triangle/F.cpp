#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    while(scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        ll a = x2 - x1, b = y2 - y1;
        ll c = x3 - x1, d = y3 - y1;
        ll ans = abs(a * d - b * c);
        printf("%lld\n", ans * 11);
    }
    return 0;
}