#include <cstdio>
typedef long long ll;
int n;
inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    while((n = rea()) != 0)
    {
        if(n <= 3) puts("1");
        else if(n == 4) puts("2");
        else printf("%d\n", n);
    }
    return 0;
}