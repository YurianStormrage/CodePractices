#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e5+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n, k;
int l[N], r[N], ans[N];

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); k = read();
        for(int i = 1; i <= n; ++i)
        {
            l[i] = read();
            r[i] = read();
        }
        r[0] = 1e9; bool flag = 0;
        for(int i = 1; i <= n; ++i)
        {
            l[i] = max(l[i], l[i-1] - k);
            r[i] = min(r[i], r[i-1] + k);
            if(l[i] > r[i]) {flag = 1; break;}
        }
        if(flag) {printf("NO\n"); continue;}
        for(int i = n; i >= 1; --i)
        {
            l[i] = max(l[i], l[i-1] - k);
            r[i] = min(r[i], r[i-1] + k);
            if(l[i] > r[i]) {flag = 1; break;}
        }
        if(flag) {printf("NO\n"); continue;}
        puts("YES");
        for(int i = 1; i < n; ++i) printf("%d ", l[i]);
        printf("%d\n", l[n]);
    }
    return 0;
}