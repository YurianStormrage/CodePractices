#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f ? x : -x;
}
int main()
{
    int n = read(), m = read(); read();
    int k = read();

    int ans = 0;
    ull animals = 0, left = 0;

    for(int i = 0; i < n; ++i) animals |= read();
    // for(int i = 0; i < m; ++i) {
    //     if(!(animals & 1ull << read())) // 1ull
    //         k --;
    //     read();
    // }
    // 重复减 k
    for(int i = 0; i < m; ++i) left |= 1ull << read(), read();
    for(int i = 0; i < k; ++i) ans += !(left >> i & 1) || animals >> i & 1;
    if(ans == 64 && n == 0) puts("18446744073709551616");
    else printf("%llu", ans == 64 ? -n : (1ull << ans) - n); // %llu
    return 0;
}