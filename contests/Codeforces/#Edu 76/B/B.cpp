#include <cstdio>
typedef long long ll;
int q, x, y;
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        x = read(); y = read();
        bool flag;
        if(x == 1) flag = y==1;
        else if(x == 2 || x == 3) flag = y<=3;
        else flag = 1;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}