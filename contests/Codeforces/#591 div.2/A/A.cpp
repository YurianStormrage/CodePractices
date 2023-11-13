#include <cstdio>
int q, n;
inline int read()
{
    int x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
    return f? x : -x;
}
int main()
{
    q = read();
    for(int i = 1; i <= q; ++i)
    {
        n = read();
        if(n <= 4) printf("%d\n",4-n);
        else if(n&1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}