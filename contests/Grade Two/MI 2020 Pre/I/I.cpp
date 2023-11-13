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
bool vis[N][N], sym[N][N];
int ans;
bool dfs(int x, int y)
{
    if(vis[x][y]) return sym[x][y];
    vis[x][y] = 1;
    if(mp[x][y] == 'W') return x == 1 || dfs(x - 1, y)? sym[x][y] = 1 : 0;
    else if(mp[x][y] == 'A') return y == 1 || dfs(x, y - 1)? sym[x][y] = 1 : 0;
    else if(mp[x][y] == 'S') return x == n || dfs(x + 1, y)? sym[x][y] = 1 : 0;
    else return y == m || dfs(x, y + 1)? sym[x][y] = 1 : 0;
}
int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; ++i)
        scanf("%s", mp[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(!vis[i][j])
                dfs(i, j);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            ans += sym[i][j];
    printf("%d", ans);
    return 0;
}