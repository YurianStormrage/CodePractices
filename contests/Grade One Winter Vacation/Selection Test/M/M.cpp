#include <cstdio>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    if(f) return -x;
    return x;
}
int main()
{
    int T = read();
    while(T--)
    {
        int x, y;
        x = read(); y = read();
        if(x == 1 && y == 1)
        {
            printf("1\n");
            continue;
        }
        if(x == y)
        {
            printf("-1\n");
            continue;
        }
        int ans = 0;
        while(x != 1 || y != 1)
        {
            if(x > y)
            {
                ans += x / y;
                x %= y;
                if(!x)
                {
                    if(y != 1) ans = -1;
                    break;
                }
            }
            else if(x < y)
            {
                ans += y / x;
                y %= x;
                if(!y)
                {
                    if(x != 1) ans = -1;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}