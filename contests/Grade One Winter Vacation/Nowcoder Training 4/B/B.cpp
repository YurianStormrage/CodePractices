#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)1e6+2, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int n, c;
int pri[N], pf[N], cnt;
int gcd(int a, int b) {return b? gcd(b, a%b) : a;}
int main()
{
    for(int i = 2; i < N; ++i)
    {
        if(!pf[i]) pri[++cnt] = pf[i] = i;
        for(int j = 1; j <= cnt && i*pri[j] < N; ++j)
        {
            pf[i*pri[j]] = pri[j];
            if(i%pri[j] == 0) break;
        }
    }

    int T = read();
    while(T--)
    {
        n = read(); c = read();
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        ll ans = 1;
        do
        {
            ans = ans * c % mod;
            n /= pf[n];
        }while(n > 1);
        printf("%d\n", ans);
    }
    return 0;
}