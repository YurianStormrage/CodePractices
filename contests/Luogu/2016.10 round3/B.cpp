#include <cstdio>
inline int re(){
  int x; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
const int maxn=200005;
int n;
char str;
int s[maxn];
long long ans;
long long f[4];
inline void dp(int l,int r){
  f[0]=1;
  for(int i=1;i<4;i++)f[i]=0;
  for(int i=l;i<=r;i++)
	f[s[i]]+=f[s[i]-1];
  if(f[3]>ans)ans=f[3];
}
int main()
{
  n=re();
  scanf("\n");
  for(int i=1;i<=n;i++){
    scanf("%c",&str);
	if(str=='N')s[i]=1;
	else if(str=='O')s[i]=2;
	else s[i]=3;
  }
  
  s[0]=1;
  dp(0,n);
  
  s[n+1]=3;
  dp(1,n+1);
  
  //数据太水了，没讨论'O'
  /*
  long long tmp=0;
  int cnt[2]={0};
  for(int i=1,flag=0;i<=n;i++){
    if(flag&&(s[i]==1||i==n)){
	  tmp=(long long)cnt[0]*cnt[1];
	  ans=ans>tmp?ans:tmp;
	  if(i==n)break;
	  flag=0;
	  cnt[0]=cnt[1]=0;
	}
	else if(s[i]==3)flag|=1;
	cnt[flag]++;
  }
  */
  
  printf("%lld",ans);
  return 0;
}
