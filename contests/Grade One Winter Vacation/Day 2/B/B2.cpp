#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int a[100010];
int rea()
{
    int x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    int n, x, y;
    while((n = rea()) != 0)
    {
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; ++i)
        {
            x = rea(); y = rea();
            ++a[x];
            --a[y+1];
        }
        for(int i = 1; i <= n; ++i)
        {
            a[i] += a[i-1];
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
