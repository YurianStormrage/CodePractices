#include <cstdio>
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}
int a, b, d, t;
int main()
{
    for(int T = read(); T--;)
    {
        a = read(); b = read(); d = read(); t = read();
        printf("%d\n", d);
    }
    return 0;
}