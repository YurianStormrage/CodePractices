#include <bits/stdc++.h>
using namespace std;
const long long INF=LLONG_MAX;
int T,n,m,s,t;
long long x;
char str[200005];
struct apple
{
    int u,v;
    long long w;
    apple(int x,int y,long long z){u=x;v=y;w=z;}
};
vector<apple> edge;
vector<int> G[200005];
void Addedge(int u,int v,long long w)
{
    edge.push_back(apple(u,v,w));
    int m=edge.size();
    G[u].push_back(m-1);
}
struct s_node
{
    int id;
    long long d;
    s_node(int x,long long y){id=x;d=y;}
    bool operator<(const s_node &a) const
    {
        return d>a.d;
    }
};
void dijkstra()
{
    long long dist[200005];
    bool vist[200005];
    for(int i=0;i<=n*2;i++)
        dist[i]=INF,vist[i]=false;
    dist[0]=0;
    priority_queue<s_node> q;
    q.push(s_node(0,dist[0]));
    while(!q.empty())
    {
        s_node tmp=q.top();
        q.pop();
        int u=tmp.id;
        long long d=tmp.d;
        if(vist[u]) continue;
        vist[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            int v=edge[G[u][i]].v;
            long long w=edge[G[u][i]].w;
            if(vist[v]) continue;
            if(dist[v]>d+w)
            {
                dist[v]=d+w;
                q.push(s_node(v,dist[v]));
            }
        }
    }
    printf("%lld\n",min(dist[t], dist[t+n]));
}
char tmp[5] = "LRM";
void add(int u, int v, long long w) {
    Addedge(u, v, w);
    Addedge(v, u, w);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%lld",&n,&m,&s,&t,&x);
        scanf("%s",str+1);
        if (str[s] == 'L' || str[s] == 'M') 
            add(0, s, 0);
        if (str[s] == 'R' || str[s] == 'M')
            add(0, s+n, 0);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            long long w;
            scanf("%d%d%lld",&u,&v,&w);
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1; j++)
                    if ((str[u] == tmp[i] || str[u] == 'M') && (str[v] == tmp[j] || str[v] == 'M'))
                        add(u+i*n, v+j*n, w+x*(i^j));
        }
        dijkstra();
        for(int i=0;i<=n*2;i++)
            G[i].clear();
        edge.clear();
    }
    return 0;
}