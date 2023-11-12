// 偏序集最长链的元素数目等于最小反链划分的反链数目
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}

const int N = 20;
int n, m;
bool edge[N][N];
int vertex_color[N];
int cnt = 0, ans = N;

bool check_color(const int& u, const int& c)
{
    for(int i = 1; i <= n; ++i)
        if(edge[u][i] && vertex_color[i] == c)
            return false;
    return true;
}

void dfs(const int& u)
{
    if(cnt > ans) return ;
    if(u > n) {
        ans = min(ans, cnt);
        return ;
    }
    for(int i = 1; i <= cnt; ++i) // don't start with 0
        if(check_color(u, i)) {
            vertex_color[u] = i;
            dfs(u + 1);
            vertex_color[u] = 0;
        }
    ++ cnt;
    vertex_color[u] = cnt;
    dfs(u + 1);
    vertex_color[u] = 0;
    -- cnt;
}

int main()
{
    n = read(); m = read();
    for(int i = 0, u, v; i < m; ++i) {
        u = read(), v = read();
        edge[u][v] = edge[v][u] = 1;
    }
    dfs(1);
    printf("%d", ans - 1);
    return 0;
}