#include <cstdio>
#define L(a) need[a].l
#define R(a) need[a].r
#define D(a) need[a].d
inline int re(){
  int x=0;char ch;
  while((ch=getchar())>'9'||ch<'0');
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48;
  return x;
}
const int maxn=1000005,maxm=1000005;
int n,m;
int room[maxn];
long long day[maxn],now;
struct ope{
  int d,l,r;
}need[maxm];
int ans;
int main()
{
//	freopen("classroom.in","r",stdin);
//	freopen("classroom.out","w",stdout);
	n=re(); m=re();
	for(int i=1;i<=n;i++)room[i]=re();
	for(int i=1;i<=m;i++){
	  D(i)=re(); L(i)=re(); R(i)=re();
	  day[L(i)]+=D(i); day[R(i)+1]-=D(i);
	}
	
	ans=m;
	for(int i=1;i<=n;i++){
	  now+=day[i];
	  while(now>room[i]){
	    day[L(ans)]-=D(ans);
		day[R(ans)+1]+=D(ans);
		if(L(ans)<=i&&i<=R(ans))now-=D(ans);
		ans--;
	  }
	}
	if(ans==m)printf("0");
	else printf("-1\n%d",ans+1);
	return 0;
}
