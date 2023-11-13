#include <cstdio>
typedef long long ll;
int q, n, x, a, b;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline int Min(int a, int b){return a<b?a:b;}
inline void Swap(int& a, int& b){a=a^b;b=a^b;a=a^b;}
int main()
{
    q = read();
    while(q--)
    {
        n = read(); x = read(); a = read(); b = read();
        if(a > b) Swap(a, b);
        printf("%d\n",b-a+Min(x,n-b+a-1));
    }
    return 0;
}