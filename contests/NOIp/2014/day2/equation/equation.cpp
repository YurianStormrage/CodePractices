#include <cstdio>
#include <cstring>
const int maxn=105,maxm=1000005;
char s[10050];
int len;
int n,m;
int a[maxn][3];
int p[3]={10007,30071,12323};
int f[maxm][3];
int ans[maxm];
inline bool check(int i,int j){
  long long tmp=0;
  for(int l=n;l>=0;l--)
    tmp=(tmp*i+a[l][j])%p[j];
  return tmp!=0;
}
int main()
{
  freopen("equation.in","r",stdin);
  freopen("equation.out","w",stdout);
  
  scanf("%d%d",&n,&m);
  for(int i=0,flag=1;i<=n;i++,flag=1){
    scanf("%s",s);
	len=strlen(s);
	  for(int k=0;k<len;k++){
	    if(s[k]=='-')flag=-1;
	    else
		  for(int j=0;j<3;j++)
		    a[i][j]=(a[i][j]*10+s[k]-48)%p[j];
	  }
	if(flag==-1)
	  for(int j=0;j<3;j++)
	    a[i][j]=p[j]-a[i][j];
  }
  
  for(int j=0;j<3;j++)
    for(int i=0;i<p[j];i++)
	  f[i][j]=check(i,j);
	  
  for(int i=1,flag=1;i<=m;i++,flag=1){
    for(int l=0;l<3;l++)
	  if(f[i%p[l]][l])
	    {flag=0; break;}
	if(flag)ans[++ans[0]]=i;
  }
  
  for(int i=0;i<=ans[0];i++)
    printf("%d\n",ans[i]);
  return 0;
}
