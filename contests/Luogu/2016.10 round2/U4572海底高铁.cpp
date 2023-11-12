#include <cstdio>
#define Min(a,b) a<b?a:b
#define Max(a,b) a>b?a:b
inline int re(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=x*10+ch-48;
  return x;
}
const int maxn=100005,maxm=100005;
typedef long long ll;
int n,m;
int a[maxn],b[maxn],c[maxn];
int cover[maxn];
ll ans;
int main()
{
  //inti
  n=re(); m=re();
  int now=re();
  for(int i=2,to;i<=m;i++){
    to=re();
	cover[Min(now,to)]++;
	cover[Max(now,to)]--;
	now=to;
  }
  for(int i=1;i<n;i++){
    a[i]=re();
	b[i]=re();
	c[i]=re();
  }
  
  for(int i=1,now=0;i<n;i++){
    now+=cover[i];
	ans+=Min((ll)a[i]*now,(ll)b[i]*now+c[i]);
  }
  
  printf("%lld",ans);
  return 0;
}
