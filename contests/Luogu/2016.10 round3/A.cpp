#include <cstdio>
#include <algorithm>
#define Min(a,b) a<b?a:b
#define Max(a,b) a>b?a:b
const int maxn=105,maxm=105,maxk=10005;
int n,k;
int grp[maxn][maxm];
int f[maxn][maxm*100];
int L,R;
int main()
{
  scanf("%d%d",&n,&k);
  for(int i=1,ma=0,mi=200;i<=n;i++,ma=0,mi=200){
    scanf("%d",&grp[i][0]);
	for(int j=1;j<=grp[i][0];j++){
	  scanf("%d",&grp[i][j]);
	  ma=Max(ma,grp[i][j]);
	  mi=Min(mi,grp[i][j]);
	}
	grp[i][grp[i][0]+1]=mi;
	grp[i][grp[i][0]+2]=ma;
	L+=mi;
	R+=ma;
  }
  
  f[0][0]=1;
  for(int i=1;i<=n;i++)
    for(int l=1;l<=grp[i][0];l++)
      for(int j=grp[i][l];j<=R;j++){
	  if(f[i][j]<=k&&k>f[i][j]+f[i-1][j-grp[i][l]])
	    f[i][j]+=f[i-1][j-grp[i][l]];
	  else f[i][j]=k;
	}
	
  for(int i=L;i<=R;i++){
    while(f[n][i]&&k){
	  printf("%d ",i);
	  f[n][i]--;
	  k--;
	}
	if(!k)return 0;
  }
  return 0;
}
