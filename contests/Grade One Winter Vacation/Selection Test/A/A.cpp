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
int a[27];
int main()
{
    int T = read();
    while(T--)
    {
        for(int i = 1; i <= 26; ++i) a[i] = read();
        int tmp = 0;
        for(int i = 1; i <= 26; ++i)
        {
            tmp += a[i] >> 1;
        }
        printf("%d\n", tmp<<1);
    }
    return 0;
}