#include <cstdio>
using namespace std;
typedef long long ll;
int q;
ll n, ans;
int num[39];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        ans = n = read();
        int k = 0, pos = -1;
        while(n)
        {
            num[k] = n%3;
            n /= 3;
            if(num[k] == 2) pos = k;
            ++k;
        }
        if(pos == -1) {printf("%lld\n",ans); continue;}
        num[k] = 0;
        for(int i = pos+1; i <= k; ++i) if(!num[i]) {pos = i; break;}
        int i = 1; ll tmp = 1;
        for(; i <= pos; ++i) tmp *= 3; ans = tmp;
        for(; i <= k; ++i)
        {
            tmp *= 3;
            if(num[i]) ans += tmp;
        } 
        printf("%lld\n",ans);
    }
    return 0;
}