#include <cstdio>
int n;
inline int read()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(j&1) printf("%d ",(j-1)*n+i);
            else printf("%d ",j*n-i+1);
        }
        putchar('\n');
    }
    return 0;
}