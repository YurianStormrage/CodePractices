#include <cstdio>
#define Max(a,b) a>b?a:b
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=x*10+ch-48;
  return x;
}
const int maxn=50005;
int n,m;
int fa[maxn][17],dis[maxn][17];
int deep[maxn],now,MaxL;
int Q[maxn];
struct edge{
  int to,w;
  edge* next;
  edge(int T,int W,edge* N):to(T),w(W),next(N){}
}*head[maxn];
inline void addedge(int u,int v,int d){
  edge* p=new edge(v,d,head[u]);
  head[u]=p;
}

inline void dfs(int s){
  for(edge* i=head[s];i;i=i->next)if(i->to!=fa[s][0])
  {
    fa[i->to][0]=s;
	dis[i->to][0]=i->w;
	deep[i->to]=deep[s]+1;
	now+=i->w;
	dfs(i->to);
	now-=i->w;
  }
  if(!head[s]&&MaxL<now)MaxL=now;
}

bool vis[maxn];
inline bool getflag(int s){
  if(vis[s])return 1;
  if(!head[s])return 0;
  for(edge* i=head[s];i;i=i->next)
    if(!getflag(i->to))
	  return 0;
  return 1;
}
inline bool check(int mid){
  for(int i=1;i<=n;i++)vis[i]=0;
  for(int i=1;i<=Q[0];i++){
    int now=Q[i];
	for(int j=0;j<=17;j++)
	  if(deep[fa[now][j]])
	    now=fa[now][j];
	vis[now]=1;
  }
  return getflag(1);
}
int main()
{
  freopen("blockade.in","r",stdin);
  freopen("blockade.out","w",stdout);
  n=re();
  for(int i=1,u,v,d;i<n;i++){
    u=re(); v=re(); d=re();
	addedge(u,v,d); addedge(v,u,d);
  }
  fa[1][0]=1; dfs(1);
  for(int i=1;i<=17;i++)
    for(int j=1;j<=n;j++){
	  dis[j][i]=Max(dis[j][i],dis[fa[j][i-1]][i-1]);
	  fa[j][i]=fa[fa[j][i-1]][i-1];
	}
  m=re();
  for(int i=1;i<=m;i++)
    Q[++Q[0]]=re();
  int l=0,r=MaxL+1,mid;
  while(l<r-1){
    mid=(l+r)>>1;
	if(check(mid))r=mid;
	else l=mid;
  }
  if(r==MaxL)printf("-1");
  else printf("%d",mid);
  return 0;
}
