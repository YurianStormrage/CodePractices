#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = (int)2e5+2;
const ll inf = LLONG_MAX;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int n, m, s, t, x;
char type[N];
char tp[3] = "LR";

struct Edge
{
    int v, w;
    Edge(){}
    Edge(int _v=0, int _w=0): v(_v), w(_w) {}
};
vector<Edge> edge;
vector<int> hd[N];
inline void ADD(int u, int v, int w)
{
    edge.push_back(Edge(v, w));
    int tot = edge.size();
    hd[u].push_back(tot-1);
}
inline void addedge(int u, int v, int w)
{
    ADD(u, v, w);
    ADD(v, u, w);
}

ll dis[N];
bool vis[N];
void dijkstra()
{
    for(int i = n<<1; i >= 0; --i) dis[i] = inf, vis[i] = 0;
    dis[0] = 0;
    using node = pair<ll, int>;
    priority_queue<node, vector<node>, greater<node>> h;
    h.push(node(0, 0));
    while(!h.empty())
    {
        node now = h.top();
        h.pop();
        int u = now.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = hd[u].size()-1, v, d; i >= 0; --i)
        {
            v = edge[hd[u][i]].v;
            if(vis[v]) continue;
            d = edge[hd[u][i]].w;
            if(dis[v] > dis[u] + (ll)d)
            {
                dis[v] = dis[u] + (ll)d;
                h.push(node(dis[v], v));
            }
        }
    }
    return ;
}

int main()
{
    for(int T = read(); T--;)
    {
        n = read(); m = read();
        s = read(); t = read(); x = read();
        scanf("%s", type+1);
        for(int i = n<<1; i >= 0; --i) hd[i].clear();
        edge.clear();
        for(int i = 1; i <= n; ++i) addedge(i, i+n, x);
        for(int i = 1, u, v, w; i <= m; ++i)
        {
            u = read(); v = read(); w = read();
            if (type[v] == 'R' || type[v] == 'M')
                addedge(u+n, v+n, w);
            if (type[v] == 'L' || type[v] == 'M')
                addedge(u, v, w);
        }
        if(type[s] == 'L') addedge(0, s, 0);
        else if(type[s] == 'R') addedge(0, s+n, 0);
        else addedge(0, s, 0), addedge(0, s+n, 0);
        dijkstra();
        printf("%lld\n", min(dis[t], dis[t+n]));
    }
    return 0;
}