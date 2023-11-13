#include <cstdio>
#define Max(a, b) (a > b ? a : b)
int q, n;
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        int l = 1000, r = 0;
        n = read();
        for(int i = 1; i <= n; ++i)
        {
            if(getchar() == '1')
            {
                if(l == 1000) l = i;
                r = i;
            }
        }
        printf("%d\n",Max(n, Max(r<<1, (n-l+1)<<1)));
    }
    return 0;
}