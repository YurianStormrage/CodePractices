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

struct node
{
    int a, b;
    node() {}
    node(int A, int B):a(A), b(B) {}
    inline bool operator<(const node& x) const
    {return b > x.b;}
};

int ans[N], cnt;
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

int main()
{
    freopen("A.out", "r", stdin);
    int T = read();
    while(T--)
    {
    int p = read();
    int a = read(), b;
    if(a == -1) continue;
    bool flag = 1;
    for(int i = 2; i < p; ++i)
    {
        b = read();
        if((a<<1)%p == b || a*3%p == b) a = b;
        else {flag = 0; break;}
    }
    if(!flag) printf("Wrong! %d : %d and %d\n", p, a, b);
    printf("Right\n");
    }
    return 0;
}