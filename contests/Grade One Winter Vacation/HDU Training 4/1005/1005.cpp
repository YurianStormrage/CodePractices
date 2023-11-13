#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2, mod = (int)1e9+7;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}
int n;
int s[N], cnt;
int g[N], f[N];
unordered_map<string, int> q;
int main()
{
    for(int T = read(); T--;)
    {
        n = read();
        cnt = 0;
        q.clear();
        for(int i = 1; i <= n; ++i)
        {
            char tp[11];
            scanf("%s", tp);
            string tmp = tp;
            if(!q[tmp]) q[tmp] = ++cnt;
            s[i] = q[tmp];
        }
        g[0] = f[0] = f[1] = 1; g[1] = 0; 
        for(int i = 2; i <= n; ++i)
        {
            g[i] = f[i-2];
            f[i] = f[i-1];
            if(s[i] != s[i-1]) f[i] = (f[i] + g[i]) % mod;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}