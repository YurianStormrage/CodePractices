#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())<='9'&&ch>='0')
    x=x*10+ch-48;
  return x;
}
const int maxn=1005;
int n;
struct people{int a,b;}p[maxn];
inline bool operator <(people x,people y){return x.a*x.b<y.a*y.b;}
int len1,c[20000],len2,key[20000],len3,ans[20000];
inline void ce(int x){
  for(int i=0;i<len1;i++)c[i]*=x;
  for(int i=0;i<len1;i++){
	c[i+1]+=c[i]/10;
	c[i]%=10;
	if(c[len1])len1++;
  }
}
inline bool check(int i){
  if(i==-1)return 0;
  if(key[i]<ans[i]) return 0;
  return key[i]>ans[i]?1:check(i-1);
}
inline void cu(int x){
  memset(key,0,sizeof(key));
  len2=0;
  for(int i=len1-1,now=0;i>=0;i--){
    now=now*10+c[i];
	if(now>=x){
	  key[i]=now/x;
	  now%=x;
	  if(!len2) len2=i+1;
	}
  }
  if(len3<len2||(len3==len2&&check(len2-1))){
    len3=len2;
	for(int i=0;i<len2;i++) ans[i]=key[i];
  }
}
int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  n=re();
  p[0].a=re();p[0].b=re();
  for(int i=1;i<=n;i++){p[i].a=re();p[i].b=re();}
  sort(p+1,p+n+1);
  len1=1; c[0]=1; ce(p[0].a);
  for(int i=1;i<=n;i++){
    cu(p[i].b);
	ce(p[i].a);
  }
  if(!len3)printf("0");
  else for(int i=len3-1;i>=0;i--) printf("%d",ans[i]);
  return 0;
}
