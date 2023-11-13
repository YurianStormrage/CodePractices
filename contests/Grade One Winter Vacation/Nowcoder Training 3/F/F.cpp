#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)2e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    if(f) return -x;
    return x;
}
int a, b;
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
        a = read(); b = read();

        if(b == 1) {printf("-1 -1 -1 -1\n"); continue;}

        int tmp = gcd(a, b);
        if(tmp != 1)
        {
            int x = a/tmp, y = b/tmp;
            printf("%d %d 1 %d\n", x+1, y, y);
            continue;
        }

        int tmpb = b;
        while(tmpb > 1 && tmpb % pf[b] == 0) tmpb /= pf[b];
        if(tmpb == 1) {printf("-1 -1 -1 -1\n"); continue;}
        
        int q = pf[b], x = 0;
        int p = b/q;
        while(p % q == 0) p /= q;
        p = pf[p];
        for(int i = 1; i < q; ++i)
        {
            if((a + i * p) % q == 0)
            {
                x = i;
                break;
            }
        }
        printf("%d %d %d %d\n", (a+x*p)/q, b/q, x, b/p);
    }
    return 0;
}