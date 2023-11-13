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

const int N = 1e5 * 2 + 1;

int dp[11][N];

int main()
{
    int T = read();
    for(int Case = 1; Case <= T; ++Case) {
        int n = read(), b = read();
        int cost[11][5] = {0}, value[11][5] = {0};
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= b; ++j)
                dp[i][j] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 4; ++j) {
                cost[i][j] = read();
                value[i][j] = read();
            }
        }
        for(int v = 0; v <= b; ++v) {
            for(int i = 1; i <= n; ++i) {
                dp[i][v] = dp[i - 1][v];
                for(int j = 1; j <= 4; ++j) {
                    
                    if(v >= cost[i][j])
                        dp[i][v] = max(dp[i][v], dp[i - 1][v - cost[i][j]] + value[i][j]);
                    // else
                    //     dp[i][v] = max(dp[i][v], dp[i - 1][v]);
                }
            }
        }
        printf("Budget #%d: Maximum of %d lives saved.\n\n", Case, dp[n][b]);
    }
    return 0;
}