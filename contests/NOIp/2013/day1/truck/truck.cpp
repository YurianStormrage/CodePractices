#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int rd(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())<='9'&&ch>='0') x=x*10+ch-48;
  return x;
}
const int maxn=10000,maxm=50000,maxq=30000,inf=0x3f3f3f;
int n,m,q;
int tot,head[maxn];
struct edge{
  int to,w,next;
}e[maxm*2];
struct node{
  int x,y,w;
}nd[maxm];
int fa[maxn];
int f[maxn][15],deep[maxn];
int w[maxn][15];
bool vis[maxn];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool operator <(node a,node b){return a.w>b.w;}
inline void Swap(int &a,int &b,int c){c=a;a=b;b=c;}
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}
inline void add(int u,int v,int z){
  e[++tot].w=z; e[tot].to=v;
  e[tot].next=head[u];
  head[u]=tot;
}
inline int lca(int x,int y){
  if(deep[x]<deep[y])Swap(x,y,0);
/*  
  for(int i=14;i>=0;i--){
    if(deep[f[x][i]]<deep[y])continue; //有时候f[x][i]会直接跳到0上，此时x会跳到0节点然后就愉快地崩了
	  x=f[x][i];
  }
*//***********************/
  int t=deep[x]-deep[y];
  for(int i=0;i<=14;i++)//从大到小也无区别，因为是一位一位地试
    if((1<<i)&t)        //此处(1<<i)按位与是只取t的二进制数的第i位
	  x=f[x][i];
///***********************
  if(x==y)return x;
  for(int i=14;i>=0&&x!=y;i--)
    if(f[x][i]!=f[y][i])
	{x=f[x][i];y=f[y][i];} //如果超过了lca(x,y)的深度就必定相等。 因为是以2的次方的形式往上跳有跳不到的点所以要跳多次
  return f[x][0];
}

inline int ask(int t,int s){
  int now=inf,d=deep[s]-deep[t];
  for(int i=0;i<=14;i++)
    if((1<<i)&d)
	  {now=Min(now,w[s][i]); s=f[s][i];}
  return now;
}

inline void dfs(int s){
  vis[s]=1;
  //递推
  for(int i=1;i<=14;i++){
    if(deep[s]<(1<<i)) break;
	f[s][i]=f[f[s][i-1]][i-1];  //①
	w[s][i]=Min(w[s][i-1],w[f[s][i-1]][i-1]);
  }
  //
  for(int i=head[s];i;i=e[i].next)
    if(!f[e[i].to][1]){
	  deep[e[i].to]=deep[s]+1;
	  f[e[i].to][0]=s;
	  w[e[i].to][0]=e[i].w;
      dfs(e[i].to);
	}
}

int main()
{
  freopen("truck.in","r",stdin);
  freopen("truck.out","w",stdout);
  memset(w,inf,sizeof(w));
  n=rd(); m=rd();
  for(int i=1;i<=m;i++){nd[i].x=rd(); nd[i].y=rd(); nd[i].w=rd();}
  for(int i=1;i<=n;i++) fa[i]=i;
  sort(nd+1,nd+m+1);
  for(int i=1,all=0/*只能有n-1条边*/;i<=m;i++)//②
    if(find(nd[i].x)!=find(nd[i].y)){
	  add(nd[i].x,nd[i].y,nd[i].w);
	  add(nd[i].y,nd[i].x,nd[i].w);
	  fa[fa[nd[i].x]]=fa[nd[i].y]; //左边只打1层fa只是修改了nd[i].x的父节点而非整棵树的根节点的父亲
	  all++;
	  if(all==n-1) break;//注意点！！
    }
  for(int i=1;i<=n;i++)/*注意不一定每个点都能到！！*/
    if(!vis[i])
	  dfs(i);
  
  q=rd();
  for(int i=1,u,v,o;i<=q;i++){
    u=rd(); v=rd();
	//注意下面这句，不在同一棵树上就输出-1
	if(find(u)!=find(v)) printf("-1\n");
	else{
	  o=lca(u,v);
	  printf("%d\n",min(ask(o,u),ask(o,v)));
	}
  }
  return 0;
}
//重点：①树上倍增：
//f[i][j]:表示 i 点往上 2^j 层的节点
//注意真的是2^j层
//此题中树最多有2^14层，以本题为例取j最大mj为14
//查找时 j 从14到0枚举，若当前点深度deep[now]不小于2^j：直接往上跳2^j层；否则j--。
//直到跳完j
//这样可以使深度过大的树的查找时间降低到log(n)
//预处理f数组可以 dfs中递推，或参考树链剖分方式，拿到deep等数据后两重for枚举（注意本题因还有一个w数组故采用递推）
//可使用递推的题目：Noip2015Day2T3

//②最大生成树
//其实只是改一下kruskal算法
//改成边权从大到小排序
//使能取到的边一定是最大的

//③LCA：
//本题用了树上倍增来找LCA，找的同时也能找到最小载重
//
//
//
//
