#include <cstdio>
const int maxn=25;
int d,n;
int pic[130][130];
int ans,cnt;
inline void search(int sx,int sy){
  int key=0;
  for(int i=sx-d;i<=sx+d;i++)
    for(int j=sy-d;j<=sy+d;j++)if(i<=128&&j<=128&&i>=0&&j>=0)
	  key+=pic[i][j];
  if(key==ans)cnt++;
  else if(key>ans)cnt=1,ans=key;
}
int main()
{
  freopen("wireless.in","r",stdin);
  freopen("wireless.out","w",stdout);
  scanf("%d%d",&d,&n);
  for(int i=1,u,v,t;i<=n;i++){
    scanf("%d%d%d",&u,&v,&t);
	pic[u][v]=t;
  }
  for(int i=0;i<=128;i++)
    for(int j=0;j<=128;j++)
	  search(i,j);
  printf("%d %d",cnt,ans);
  return 0;
}
