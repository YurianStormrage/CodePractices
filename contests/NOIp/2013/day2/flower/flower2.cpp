#include <cstdio>
#include <algorithm>
using namespace std;
inline int lowbit(int x){return x&-x;}
inline int re(){
  int x=0; char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=x*10+ch-48;
  while((ch=getchar())<='9'&&ch>='0')
    x=x*10+ch-48;
  return x;
}
const int maxn=100005,maxh=1000050;
int n,h[maxn],mh;
int f[maxn][2];
int seg[maxh][2],;
int ans;
inline void insert(int s,int k,int x){
  for(int i=s;i<=mh;i+=lowbit(i))
    seg[i][k]=max(seg[i][k],x);
}
inline int Max(int x,int k){
  int key=0;
  for(int i=x;i;i-=lowbit(i))
    key=max(key,seg[i][k]);
  return key;
}
int main()
{
  freopen("flower.in","r",stdin);
  freopen("flower.out","w",stdout);
  n=re();
  for(int i=1;i<=n;i++){
    h[i]=re();
	mh=max(mh,++h[i]);
	f[i][0]=f[i][1]=1;
  }
  mh++;
  for(int i=1;i<=n;i++){
    f[i][0]=max(f[i][0],Max(mh-h[i]-1,0)+1);
	f[i][1]=max(f[i][1],Max(h[i]-1,1)+1);
	insert(h[i],1,f[i][0]);
	insert(mh-h[i],0,f[i][1]);
	ans=max(ans,max(f[i][1],f[i][0]));
  }
  printf("%d",ans);
  return 0;
}
