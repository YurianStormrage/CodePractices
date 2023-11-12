#include <cstdio>
#include <algorithm>
#define sort std::sort
#define Max(a,b) a>b?a:b
const int maxn=105;
int n,m;
int tot;
int next[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node{
  int h;
  int i,j;
}pic[maxn*maxn];
int h[maxn][maxn];
int f[maxn][maxn];
int ans=1;
inline bool operator <(const node& a,const node& b){return a.h<b.h;}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
	  ++tot;
	  scanf("%d",&pic[tot].h);
	  h[i][j]=pic[tot].h;
	  pic[tot].i=i; pic[tot].j=j;
	  f[i][j]=1;
	}
  
  sort(pic+1,pic+tot+1);
  
  for(int i=1,sx,sy,nx,ny;i<=tot;i++){
    sx=pic[i].i;
	sy=pic[i].j;
	for(int k=0;k<4;k++){
	  nx=sx+next[k][0];
	  ny=sy+next[k][1];
	  if(nx<1||nx>n||ny<1||ny>n)continue;
	  if(h[nx][ny]>h[sx][sy]){
	    f[nx][ny]=Max(f[nx][ny],f[sx][sy]+1);
		ans=Max(ans,f[nx][ny]);
	  }
	}
  }
  printf("%d",ans);
  return 0;
}
