#include <cstdio>
int q, a, b, c, d, k;
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
        a = read(); b = read(); c = read(); d = read(); k = read();
        int tmp1 = a/c+(a/c*c!=a), tmp2 = b/d+(b/d*d!=b);
        if(k >= tmp1+tmp2) printf("%d %d\n",tmp1, tmp2);
        else printf("-1\n");
    }
    return 0;
}