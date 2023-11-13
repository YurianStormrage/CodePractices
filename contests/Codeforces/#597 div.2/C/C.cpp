#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e5+2, mod = (int)1e9+7;
ll f[N], g[N];
char s[N];
ll ans = 1;
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    f[1] = 1;
    for(int i = 2; i <= len; ++i)
    {
        f[i] = (f[i-1]+g[i-1])%mod;
        g[i] = f[i-1];
    }
    int last = 0, cur, cnt = 0;
    for(int i = 0; i < len; ++i)
    {
        cur = s[i];
        if(cur == 'w' || cur == 'm') {putchar('0'); return 0;}
        if(cur == last) ++cnt;
        else
        {
            if((last == 'n' || last == 'u') && cnt != 1) ans = ans*(f[cnt]+g[cnt])%mod;
            cnt = 1;
        }
        last = cur;
    }
    if((last == 'n' || last == 'u') && cnt != 1) ans = ans*(f[cnt]+g[cnt])%mod;
    printf("%lld",ans);
    return 0;
}