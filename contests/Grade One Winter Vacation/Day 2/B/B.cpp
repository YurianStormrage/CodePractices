#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e5 + 2;
int n;
int ans[N];
int rea()
{
    int x = 0; char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    while((n = rea()) != 0)
    {
        
        for(int i = 1; i <= n; ++i)
        {
            ++ans[rea()];
            --ans[rea() + 1];
        }
        for(int i = 1; i <= n; ++i)
        {
            ans[0] += ans[i];
            printf("%d%c", ans[0], i == n? '\n' : ' ');
        }
        for(int i = 0; i <= n; ++i) ans[i] = 0;
        ans[n + 1] = 0;
    }
    return 0;
}