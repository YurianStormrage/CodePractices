#include <cstdio>
#include <queue>
#define queue std::queue 
const int maxn=10005,maxm=200005,inf=int(1e9);
int n,m;
int s,t;
int tot,to[maxm<<1],next[maxm<<1],head[maxn];
bool dire[maxm<<1],reached[maxn],vis[maxn],can[maxn];
int dis[maxn];
inline void addedge(int u,int v,bool flag){
  tot++;
  to[tot]=v;
  dire[tot]=flag;
  next[tot]=head[u];
  head[u]=tot;
}

queue<int>Q;
inline void bfs(int s){
  Q.push(s);
  vis[s]=1;
  reached[s]=1;
  int v;
  while(!Q.empty()){
    v=Q.front(); Q.pop();
	for(int i=head[v];i;i=next[i])if(!vis[to[i]]&&!dire[i]){
	  vis[to[i]]=1;
	  Q.push(to[i]);
	  reached[to[i]]=1;
	}
  }
}

inline void spfa(int u){
  for(int i=1;i<=n;i++)dis[i]=inf;
  Q.push(u);
  dis[u]=0;
  int v;
  while(!Q.empty()){
    v=Q.front(); Q.pop();
	for(int i=head[v];i;i=next[i])
	  if(dire[i]&&can[to[i]]&&dis[to[i]]>dis[v]+1)
	  {
	    dis[to[i]]=dis[v]+1;
	    Q.push(to[i]);
	  }
  }
}

int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  
  scanf("%d%d",&n,&m);
  for(int i=1,u,v;i<=m;i++){
    scanf("%d%d",&u,&v);
	addedge(u,v,1);
	addedge(v,u,0);
  }
  scanf("%d%d",&s,&t);
  
  vis[t]=1; reached[t]=1;
  bfs(t);
  
  for(int i=1;i<=n;i++){
    can[i]=1;
	for(int j=head[i];j;j=next[j])if(dire[j]&&!reached[to[j]])
	  can[i]=0;
  }
  
  spfa(s);
  
  if(dis[t]==inf)printf("-1");
  else printf("%d",dis[t]);
  return 0;
}
