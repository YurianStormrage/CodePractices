#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar())
        if(ch == '-') f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x<<1)+(x<<3)+(ch^48);
    return f? x : -x;
}
const int N = 3e3 + 2, M = 6e3 + 2;
const int inf = 1e9;
int n, m;
int hd[N], nxt[N + M], to[N + M], d[N + M], tot;
// 除原图的边，还添加了点0到所有点的边
int h[N], dis[N];
inline void addedge(const int u, const int v, const int w) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; d[tot] = w;}

bool spfa()
{
    queue<int> q;
    bool inq[N] = {0};
    int times[N] = {0};
    for(int i = 1; i <= n; ++i)
        h[i] = inf;
    q.push(0);
    h[0] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop(); inq[u] = 0;
        for(int i = hd[u]; i; i = nxt[i]) {
            int v = to[i];
            if(h[v] > h[u] + d[i]) {
                h[v] = h[u] + d[i];
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                    if(++times[v] == n + 1) // **n + 1** 多了点0，|V|=n+1
                        return false;
                    // 注意times更新位置，松弛一次时才加一
                    // 因为有重边，会影响搜索次数
                }
            }
        }
    }
    return true;
}

void dijkstra(const int s)
{    
    priority_queue<pair<int, int> > q;
    bool vis[N] = {0};
    for(int i = 1; i <= n; ++i) dis[i] = inf;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        // 有重边时，一个点可能没有出堆就被入堆多次
        // 因此在这里去重
        for(int i = hd[u]; i; i = nxt[i]) {
            int v = to[i], w = d[i] + h[u] - h[v];
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
}
int main()
{
    n = read(); m = read();
    for(int u, v, w; m--; ) {
        u = read(); v = read(); w = read();
        addedge(u, v, w);
    }
    for(int i = 1; i <= n; ++i) addedge(0, i, 0);
    if(!spfa()) {
        printf("-1");
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        dijkstra(i);
        ll ans = 0;
        for(int j = 1; j <= n; ++j)
            ans += 1ll * j * (dis[j] + (dis[j] == inf? 0 : h[j] - h[i]));
            // 最后减掉势能差值，消除改变边权的影响
        printf("%lld\n", ans);
    }
    return 0;
}