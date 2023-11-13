#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int q, n, a[101];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
inline bool check()
{
    for(int i = 1; i < n; ++i) if(a[i] == a[i-1]+1) return true;
    return false;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        for(int i = 0; i < n; ++i) a[i] = read();
        sort(a, a+n);
        if(check()) puts("2");
        else puts("1");
    }
    return 0;
}