#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n, m;
pair<int, int> q[10002];

int solve(int step, int n, int m)
{
    if(m == 0) return 0;
    int res = n-(n-m)%m;
    q[step].first = res;
    q[step].second = m;
    return res + solve(step+1, m, (n-m)%m);
}

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); m = read();
        if(n < m) swap(n, m);
        for(int i = 1; i <= n; ++i) q[i].first = q[i].second = 0;
        printf("%d\n", solve(1, n, m));
        for(int i = 1; q[i].first; ++i) for(int j = q[i].first; j >= 1; --j) printf("%d ", q[i].second);
        puts("");
    }
    return 0;
}