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
    freopen("test.in", "w", stdout);
    printf("100000 0\n");
    int x = 1000000000;
    for(int i = 1; i <= 100000; ++i)
    {
        x = -x;
        printf("%d ", x);
    }
    return 0;
}