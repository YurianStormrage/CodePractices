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
const int N = 1e4 + 2, M = 5e5 + 2;
const unsigned int inf = (1 << 31) - 1;
int n, m, s;
int hd[N], nxt[M], to[M], d[M], tot;
int dis[N];
inline void addedge(const int u, const int v, const int w) {nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; d[tot] = w;}
void init(int n)
{
    tot = 0;
    for(int i = 1; i <= n; ++i) hd[i] = 0, dis[i] = inf;
}
void spfa(int s, int dis[])
{
    dis[s] = 0;
    bool inq[N] = {0};
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = hd[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + d[i]) {
                dis[v] = dis[u] + d[i];
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    n = read(); m = read(); s = read();
    init(n);
    for(int i = 0, u, v, w; i < m; ++i) {
        u = read(); v = read(); w = read();
        addedge(u, v, w);
    }
    // for(int i = 0; i < m; ++i) addedge(read(), read(), read());
    spfa(s, dis);
    for(int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    return 0;
}