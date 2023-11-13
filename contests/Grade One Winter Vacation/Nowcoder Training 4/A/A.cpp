#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e6+2, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int a, b, c, d;
int main()
{
    int T = read();
    while(T--)
    {

    }
    return 0;
}