#include <cstdio>
#define To(i) e[i].to
#define W(i) e[i].w
inline int re(){
  int x=0;char ch=getchar();
  for(;ch>'9'||ch<'0';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-48;
  return x;
}
inline void Swap(int& a,int& b){int tmp=a;a=b;b=tmp;}
const int maxn=100005,maxq=50005;
int n,Q;
//点目录边权和点权
int up[maxn],p[maxn];
//邻接表
int tot,head[maxn],next[maxn<<1];
struct edge{
  int to,w;
}e[maxn<<1];
inline void addedge(int u,int v,int d){
  tot++; To(tot)=v; W(tot)=d;
  next[tot]=head[u];
  head[u]=tot;
}
//倍增初始化
int deep[maxn],fa[maxn][20],dis[maxn][20],cnt[maxn][20];
inline void dfs(int s){
  for(int i=1;i<=17;i++){
    if(deep[s]<(1<<i))break;
	fa[s][i]=fa[fa[s][i-1]][i-1];
	dis[s][i]=dis[s][i-1]+dis[fa[s][i-1]][i-1];
	cnt[s][i]=cnt[s][i-1]+cnt[fa[s][i-1]][i-1];
  }
  for(int i=head[s];i;i=next[i])if(!deep[To(i)])
  {
    fa[To(i)][0]=s;
	dis[To(i)][0]=W(i);
	cnt[To(i)][0]=p[s];
	deep[To(i)]=deep[s]+1;
	dfs1(To(i));
  }
}

int dis[maxn];
inline int LCA(int x,int y){
  bool flag=0;
  if(deep[x]<deep[y])Swap(x,y),flag=1;
  int td=deep[x]-deep[y];
  for(int i=17;i>=0;i--)
    if(deep[fa[x][i]]>=deep[y]) x=fa[x][i];
  for(int i=17;i>=0;i--){
    if(fa[x][i]!=fa[y][i])
	  x=
  }
}

inline void query(int u,int v){
  
}
int main()
{
  n=re();
  for(int i=1,u,v,d;i<n;i++){
    u=re(); v=re(); 
	addedge(u,v,d);
	addedge(v,u,d);
  }
  for(int i=1;i<=n;i++)p[i]=re();
  fa[1][0]=1; dfs(1);
  Q=re();
  for(int i=1,u,v;i<=Q;i++){
    u=re(); v=re();
	query(u,v);
  }
  return 0;
}
