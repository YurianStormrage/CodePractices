#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50000+5;
const int P=17+2;
int n,m,T,num,head[N],dis[N],father[N],deep[N],anc[N][P],flag[N];
struct edge
{
    int u,v,w;
    int next;
}ed[3*N];
void build(int u,int v,int w)
{
    ed[++num].u=u;
    ed[num].v=v;
    ed[num].w=w;
    ed[num].next=head[u];
    head[u]=num;
}
void dfs(int u)
{
    anc[u][0]=father[u];
    for (int i=1;i<=17;i++)
    anc[u][i]=anc[anc[u][i-1]][i-1];
    for (int i=head[u];i!=-1;i=ed[i].next)
    {
        int v=ed[i].v;
        if (flag[v]==0)
        {
            flag[v]=1;
            deep[v]=deep[u]+1;
            dis[v]=dis[u]+ed[i].w;
            father[v]=u;
            dfs(v);
        }
    }
}
int LCA(int x,int y)
{
    int a=x,b=y;
    if (deep[x]<deep[y]) {swap(x,y);swap(a,b);}
    for (int i=17;i>=0;i--)
    if (deep[y]<=deep[anc[x][i]]) x=anc[x][i];
    if (x==y) return dis[a]-dis[x];
    for (int i=17;i>=0;i--)
    if (anc[x][i]!=anc[y][i]) {x=anc[x][i];y=anc[y][i];}
    return dis[a]+dis[b]-2*dis[anc[x][0]];
}
void clear()
{
    num=0;
    memset(head,-1,sizeof(head));
    memset(anc,-1,sizeof(anc));
    memset(deep,0,sizeof(deep));
    memset(dis,0,sizeof(dis));
    memset(flag,0,sizeof(flag));
    memset(father,0,sizeof(father));
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        clear();
        scanf("%d%d",&n,&m);
        for (int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            build(u,v,w);
            build(v,u,w);
        }
        flag[1]=1;
        dfs(1);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",LCA(x,y));
        }
    }
    return 0;
}
