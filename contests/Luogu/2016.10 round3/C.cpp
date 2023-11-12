#include <cstdio>
#include <queue>
#define queue std::queue
#define D(s) nd[s].dis
#define C(s) nd[s].cnt
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
const int maxn=100005,inf=0x3fffffff,maxm=200005;
int n,m,q;
int ans;
struct node{
  int dis;
  int cnt;
  node(){dis=inf;cnt=0;}
}nd[maxn];

int x[maxm],y[maxm];
struct edge{
  int to;
  edge* next;
  bool flag;
  edge(int t,edge* N):to(t),next(N){flag=1;}
}*head[maxn];
inline void addedge(int u,int v){
  edge* p=new edge(v,head[u]);
  head[u]=p;
}

queue<int>Q;
inline void BFS(int s){
  Q.push(s);
  D(s)=0; C(s)++;
  int h;
  while(!Q.empty()){
    h=Q.front(); Q.pop();
	for(edge* i=head[h];i;i=i->next){
	  if(D(i->to)>=D(h)+1){
	    Q.push(i->to);
		D(i->to)=D(h)+1;
		C(i->to)++;
	  }
	  else i->flag=0;
	}
  }
}

queue<int>Q2;
inline void del(int p){
  if(D(x[p])==D(y[p]))return;
  
  int t=D(x[p])>D(y[p])?x[p]:y[p];
  Q2.push(t);
  int h;
  while(!Q2.empty()){
    h=Q2.front(); Q2.pop();
	if(--C(h)==0)ans++;
	for(edge* i=head[h];i;i=i->next){
	  
	}
  }
}

int main()
{
  n=re(); m=re(); q=re();
  for(int i=1,u,v;i<=m;i++){
    u=re(); v=re();
	addedge(u,v);
	addedge(v,u);
	x[i]=u; y[i]=v;
  }
  
  BFS(1);
  
  for(int i=1,p;i<=n;i++){
    p=re();
	del(p);
  }
  return 0;
}
