#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = (int)1e5 + 2, M = (int)2e5 + 2;
const ll inf = -1ull>>1;
int n, m;
int hd[N], nxt[M], to[M], a[M], b[M], tot;
inline void addedge(int u, int v, int _a, int _b)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v; a[tot] = _a; b[tot] = _b;
}
ll dis[N];
bool vis[N];

struct node
{
    int v;
    ll d;
    node(int _v, ll _d):v(_v), d(_d){}
    bool operator <(const node &x) const {return d > x.d;}
};
inline int rea()
{
    int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x*10+ch-48;
    return x;
}

int dijkstra()
{
    priority_queue<node> q;
    for(int i = 1; i <= n; ++i) dis[i] = inf;
    for(int i = 1; i <= n; ++i) vis[i] = 0;
    dis[1] = 1;
    q.push(node(1, 1));
    while(!q.empty())
    {
        node t = q.top();
        q.pop();
        if(t.v == n)
        {
            for(int i = 1; ; ++i)
                if((1ull<<i) > t.d)
                    return i - 1;
        }
        if(vis[t.v]) continue;
        vis[t.v] = 1;
        for(int i = hd[t.v]; i; i = nxt[i])
        {
            int v = to[i];
            if(vis[v]) continue;
            if((1 + a[i]/t.d) >= (1ull<<b[i]) && dis[v] > t.d + a[i])
            {
                dis[v] = t.d + a[i];
                q.push(node(v, dis[v]));
            }
        }
    }
    return -1;
}

int main()
{
    int T = rea();
    /*int T;
    scanf("%d", &T);*/
    while(T--)
    {
        n = rea(); m = rea();
        //scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) hd[i] = 0;
        tot = 0;
        //for(int i = 1; i <= m; ++i) addedge(rea(), rea(), rea(), rea());
        for(int i = 1; i <= m; ++i)
        {
            int u, v, a, b;
            //scanf("%d%d%d%d", &u, &v, &a, &b);
            u = rea(); v = rea(); a = rea(); b = rea();
            addedge(u, v, a, b);
        }
        //memset(to, 0, sizeof(to));
        printf("%d\n", dijkstra());
    }
    return 0;
}