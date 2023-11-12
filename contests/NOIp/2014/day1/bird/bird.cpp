#include <cstdio>
#define Min(a,b) a<b?a:b
const int maxn=10005,maxm=1005,maxk=10005,inf=int(1e9);
int n,m,k;
int x[maxn],y[maxn];
struct wall{
  int l,h;
}w[maxn];
int f[maxn][maxm];
int main()
{
  freopen("bird.in","r",stdin);
  freopen("bird.out","w",stdout);
  
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
  for(int i=0;i<=n;i++)w[i].l=0,w[i].h=m+1;
  for(int i=1,p,l,h;i<=k;i++){
    scanf("%d%d%d",&p,&l,&h);
	w[p].l=l; w[p].h=h;
  }
  
  f[0][0]=inf;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++)
	  f[i][j]=inf;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
	  if(j>x[i-1]){
	    f[i][j]=Min(f[i][j],f[i-1][j-x[i-1]]+1);
		f[i][j]=Min(f[i][j],f[i][j-x[i-1]]+1);
	  }
	  if(j==m){
	    for(int k=m-x[i-1];k<=m;k++){
		  f[i][m]=Min(f[i][m],f[i-1][k]+1);
		  f[i][m]=Min(f[i][m],f[i][k]+1);
	    }
      }
	}
	for(int j=w[i].l+1;j<=w[i].h-1;j++) if(j+y[i-1]<=w[i-1].h-1)
	  f[i][j]=Min(f[i][j],f[i-1][j+y[i-1]]);
	for(int j=1;j<=w[i].l;j++)f[i][j]=inf;
	for(int j=w[i].h;j<=m;j++)f[i][j]=inf;
  }
  
  int ans=inf,cnt=0;
  for(int i=1,flag;i<=n;i++){
    flag=0;
    for(int j=w[i].l+1;j<=w[i].h-1;j++)
	  if(f[i][j]!=inf){flag=1;break;}
	if(!flag)break;
	if(w[i].h<=m)cnt++;
	if(i==n)
	  for(int j=w[i].l+1;j<=w[i].h-1;j++)
	    if(ans>f[i][j])ans=f[i][j];
  }
  if(cnt<k)printf("0\n%d",cnt);
  else printf("1\n%d",ans);
  return 0;
}
