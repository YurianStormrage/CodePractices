#include <cstdio>
typedef long long ll;
const int N = 82;
int n, m;
int x[N], s[N];
ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) x[i] = read(), s[i] = read();
    
    return 0;
}