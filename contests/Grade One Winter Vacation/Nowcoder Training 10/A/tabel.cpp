#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e6+2, M = (int)2e6+2;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 0;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-') f = 1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return f? -x : x;
}

int p;

int tot, hd[N], to[M], nxt[M];
inline void addedge(const int& u, const int& v)
{
    nxt[++tot] = hd[u]; hd[u] = tot; to[tot] = v;
}

int cnt, pri[N], pf[N];

struct node
{
    int a, b;
    node() {}
    node(int A, int B):a(A), b(B) {}
    inline bool operator<(const node& x) const
    {return b > x.b;}
};

int ans[N], num;
bool vis[N];
int dis[N];
inline bool dijkstra(const int& u)
{
    priority_queue<node> q;
    for(int i = 1; i < p; ++i) vis[i] = 0, dis[i] = N;
    dis[u] = 0;
    q.push(node(u, 0));
    int top, d;
    while(!q.empty())
    {
        top = q.top().a; d = q.top().b;
        q.pop();
        vis[top] = 1;
        for(int i = hd[top], v; i; i = nxt[i])
        {
            v = to[i];
            if(vis[v]) continue;
            if(d+1 < dis[v])
            {
                dis[v] = d + 1;
                q.push(node(v, dis[v]));
            }
        }
    }
    for(int i = 1; i < p; ++i) if(dis[i] == N) return 0;
    return 1;
}

bool dfs(const int& u)
{
    ans[++num] = u;
    vis[u] = 1;
    if(vis[(u<<1)%p] && vis[u*3%p]) return 0;
    bool flag = 0;
    if(!vis[(u<<1)%p]) flag |= dfs((u<<1)%p);
    if(flag) return 1;
    if(!vis[u*3%p]) flag |= dfs(u*3%p);
    return flag;
    
}

int main()
{
    freopen("tabel.out", "w", stdout);
    for(int i = 2; i < N; ++i)
    {
        if(!pf[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i*pri[j] < N; ++j)
        {
            pf[i*pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    int n = read(); printf("%d\n", n);
    for(int i = 1; i <= n; ++i) printf("%d\n", pri[i]);
    return 0;
}