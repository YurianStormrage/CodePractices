#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}
const int N = 1e5 + 2;
int n;
ll a[N];
int cnt[60];
void update(ll x)
{
    int i = 0;
    while(x) {
        cnt[i++] += x & 1;
        x >>= 1;
    }
}
int solve(ll state)
{
    int len = 0;
    for(; ; ++len) if(state >> len == 0) break;
    if(len == 0) return 0;
    return cnt[len - 1];
}
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    ll state = 0, ans = 0;
    for(int i = 1; i <= n; ++i) {
        state ^= a[i];
        update(a[i]);
        //ans += solve(state);
        //printf("%lld\n", ans);
        printf("%d\n", solve(state));
    }
    return 0;
}