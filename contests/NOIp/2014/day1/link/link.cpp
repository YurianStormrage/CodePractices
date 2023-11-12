#include <cstdio>
#include <queue>
#define queue std::queue
const int maxn=200005,mod=10007;
int n;
int val[maxn];
int ans,mn;
int num[maxn],all;
int to[maxn<<1],next[maxn<<1],tot;
int head[maxn];
inline void addedge(int u,int v){
  ++tot;
  to[tot]=v;
  next[tot]=head[u];
  head[u]=tot;
}
queue<int>Q;
int vis[maxn];
inline void bfs(int s){
  for(int i=1;i<=n;i++)vis[i]=0;
  Q.push(s);
  vis[s]=1;
  int p,tmp;
  while(!Q.empty()){
    p=Q.front(); Q.pop();
	if(vis[p]<3){
	  for(int i=head[p];i;i=next[i])
	    if(vis[to[i]]==0){
		  vis[to[i]]=vis[p]+1;
		  Q.push(to[i]);
		}
	}
	else{
	  tmp=val[s]*val[p];
	  ans=(ans+tmp)%mod;
	  if(mn<tmp)mn=tmp;
	}
  }
}
int main()
{
  freopen("link.in","r",stdin);
  freopen("link.out","w",stdout);
  scanf("%d",&n);
  for(int i=1,u,v;i<n;i++){
    scanf("%d%d",&u,&v);
	addedge(u,v);
	addedge(v,u);
  }
  for(int i=1;i<=n;i++)
    scanf("%d",&val[i]);
  
  long long now;
  for(int i=1,max1,max2;i<=n;i++){
    max1=0; max2=0;
	all=0; num[0]=0;
	for(int j=head[i];j;j=next[j]){
	  num[++all]=val[to[j]];
	  num[0]+=val[to[j]];
	  if(val[to[j]]>max1){
	    max2=max1;
		max1=val[to[j]];
	  }
	  else if(val[to[j]]>max2)
	    max2=val[to[j]];
	}
	now=(long long)num[0]*num[0];
	for(int k=1;k<=all;k++)
	  now-=num[k]*num[k];
	ans=(ans+now)%mod;
	if(max1*max2>mn)mn=max1*max2;
  }
  printf("%d %d",mn,ans);
  return 0;
}
