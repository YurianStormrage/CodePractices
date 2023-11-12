#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
inline int rd(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())<='9'&&ch>='0') x=x*10+ch-48;
  return x;
}
inline void Swap(int &a,int &b,int c){c=a;a=b;b=c;}
const int maxn=10000,maxm=50000,maxq=30000,inf=0x3f3f3f;
int n,m,q;
int tot,head[maxn];
struct edge{
  int to,w,next;
}e[maxm*2];
struct que{int x,y;}qn[maxq];
inline bool operator <(que a,que b){return a.x<b.x;}
int dis[maxn];
bool vis[maxn];
queue <int> Q;
inline void add(int u,int v,int z){
  e[++tot].w=z; e[tot].to=v;
  e[tot].next=head[u];
  head[u]=tot;
}
int book[maxn];
inline void spfa(int s){
  for(int i=1;i<=n;i++) dis[i]=-1,book[i]=0;;
  dis[s]=0;
  Q.push(s);
  int now;
  while(!Q.empty()){
    now=Q.front(); Q.pop();
	if(book[now]) continue; book[now]=1;
	for(int i=head[now];i;i=e[i].next)
	  if(dis[e[i].to]<e[i].w){
	    dis[e[i].to]=e[i].w;
		Q.push(e[i].to);
	  }
  }
}
int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  n=rd(); m=rd();
  for(int i,u,v,w;i<=m;i++){
    u=rd(); v=rd(); w=rd();
	add(u,v,w); add(v,u,w);
  }
  q=rd();
  for(int i=1;i<=q;i++){
    qn[i].x=rd(); qn[i].y=rd();
	if(qn[i].x>qn[i].y)
	  Swap(qn[i].x,qn[i].y,0);
  }
  sort(qn+1,qn+q+1);
  for(int i=1;i<=q;i++){
    if(!vis[qn[i].x]){
	  spfa(qn[i].x);
	  vis[qn[i].x]=1;
	}
	printf("%d\n",dis[qn[i].y]);
  }
  return 0;
}
