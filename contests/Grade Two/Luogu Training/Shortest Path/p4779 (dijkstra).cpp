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
const int N = 1e5 + 2, M = 2e5 + 2;
const int inf = 0x3f3f3f3f;
int n, m, s;
int hd[N], nxt[M], to[M], d[M], tot;
int dis[N];
inline void addedge(const int u, const int v, const int w) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; d[tot] = w;}
struct cmp {
    bool operator() (int a, int b) {return dis[a] > dis[b];}
}; // 因为动态排序的原因？？
void dijkstra(int s)
{    
    //priority_queue<int, vector<int>, cmp> q;
    priority_queue<pair<int, int> > q;
    bool vis[N] = {0};
    memset(dis, 0x3f, sizeof(dis));
    //for(int i = 1; i <= n; ++i) dis[i] = inf;
    dis[s] = 0;
    q.push(make_pair(0, s));
    //q.push(s);
    while(!q.empty()) {
        int u = q.top().second;
        //int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = hd[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + d[i]) {
                dis[v] = dis[u] + d[i];
                q.push(make_pair(-dis[v], v));
                //q.push(v);
            }
        }
    }
}
int main()
{
    n = read(); m = read(); s = read();
    for(int u, v, w; m--; ) {
        u = read(); v = read(); w = read();
        addedge(u, v, w);
    }
    dijkstra(s);
    for(int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    return 0;
}