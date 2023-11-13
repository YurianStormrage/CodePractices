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
    int T = read();
    while(T--)
    {
        int n = read();
        if(n == 1) printf("26\n");
        else if(n == 2) printf("676\n");
        else if(n == 3) printf("17576\n");
        else printf("15600\n");
    }
    return 0;
}