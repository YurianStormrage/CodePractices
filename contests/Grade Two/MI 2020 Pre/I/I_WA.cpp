#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch <'0'; ch = getchar()) if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}
const int N = 1e3 + 2;
int n, m;
char mp[N][N];
int flag[N][N], cnt[N][N];
int ans;
int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cnt[i][j] = 1;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", mp[i] + 1);
        for(int j = 1; j <= m; ++j) {
            if(mp[i][j] == 'W') {
                if(i == 1) flag[i][j] = 1;
                else {
                    cnt[i-1][j] += cnt[i][j];
                    cnt[i][j] = 0;
                }
            }
            else if(mp[i][j] == 'A') {
                if(j == 1) flag[i][j] = 1;
                else {
                    cnt[i][j-1] += cnt[i][j];
                    cnt[i][j] = 0;
                }
            }
            else if(mp[i][j] == 'S') {
                if(i == n) flag[i][j] = 1;
                else {
                    cnt[i+1][j] += cnt[i][j];
                    cnt[i][j] = 0;
                }
            }
            else {
                if(j == m) flag[i][j] = 1;
                else {
                    cnt[i][j+1] += cnt[i][j];
                    cnt[i][j] = 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            ans += flag[i][j] * cnt[i][j];
    printf("%d", ans);
    return 0;
}