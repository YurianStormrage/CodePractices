#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005,mod=99999997;
int n;
struct node{int x,id;}a[maxn],b[maxn];
int key[maxn],seg[maxn];
long long ans;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
  return x*f;
}
inline bool operator <(node a,node b){return a.x<b.x;}
inline int lowbit(int x){
  return x&-x;
}
inline int sum(int x){
  int fans=0;
  for(;x;x-=lowbit(x)) fans+=seg[x];
  return fans;
}
inline void insert(int x){for(int i=x;i<=n;i+=lowbit(i)) seg[i]++;}
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  n=read();
  for(int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
  for(int i=1;i<=n;i++) b[i].x=read(),b[i].id=i;
  sort(a+1,a+n+1); sort(b+1,b+n+1);
  for(int i=1;i<=n;i++) key[a[i].id]=b[i].id;
  for(int i=n;i>=1;i--){
    ans=(ans+sum(key[i]))%mod;
	insert(key[i]);
  }
  printf("%lld",ans);
  return 0;
}
