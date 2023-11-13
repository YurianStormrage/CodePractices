#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = (int)1e3 + 2;
int q, n;
int a[N];
ll rea()
{
    ll x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int main()
{
    q = rea();
    while(q--)
    {
        n = rea();
        for(int i = 1; i <= n; ++i) a[i] = rea();
        if(n == 1)
        {
            printf("%d\n", a[1]);
            continue;
        }
        sort(a+1, a+1+n);
        int stg = a[1] + (a[2] << 1), g1, g2;
        int ans = 0;
        while(n >= 4)
        {
            g1 = stg + a[n];
            g2 = a[n] + a[n-1] + (a[1] << 1);
            if(g1 < g2)
            {
                ans += g1;
                n -= 2;
            }
            else
            {
                ans += a[n] + a[1];
                n--;
            }
        }
        if(n == 2) ans += a[2];
        else if(n == 3) ans += a[1] + a[2] + a[3];
        printf("%d\n", ans);
    }
    return 0;
}