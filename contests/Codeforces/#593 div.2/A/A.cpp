#include <cstdio>
#define Min(a, b) ((a) < (b)? (a) : (b))
int q, a, b, c;
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        a = read(); b = read(); c = read();
        int k, ans;
        k = Min(b, c>>1);
        ans = k*3; b -= k;
        k = Min(a, b>>1);
        ans += k*3;
        printf("%d\n",ans);
    }
    return 0;
}