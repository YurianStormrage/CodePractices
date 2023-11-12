#include <cstdio>
#include <algorithm>
using namespace std;
#define H(p) p.home
#define D(p) p.dire
inline int re(){
  int x=0,f=1; char ch;
  while((ch=getchar())>'9'||ch<'0')if(ch=='-')f=-1;
  x=ch-48;
  while((ch=getchar())>='0'&&ch<='9')x=x*10+ch-48;
  return x*f;
}
const int maxn=100005;
typedef long long ll;
int n,t,q;
struct people{
  int home,dire;
}p[maxn];
bool operator <(people a,people b){return H(a)<H(b);}
ll key[maxn],ans[maxn];
bool vis[maxn];
int main()
{
  //inti
  n=re(); t=re(); q=re();
  for(int i=1;i<=n;i++){
    H(p[i])=re();
	D(p[i])=re();
  }
  for(int i=1,fi=0;i<=n;i++){
    if(D(p[i])==1){
	  fi=i;
	}
	else if(fi){
	  ll k=(H(p[i])+H(p[fi]))>>1;
	  if(H(p[i])-H(p[fi])<=t<<1){
	    key[++key[0]]=k;
		ans[fi]=k; ans[i]=k;
	  }
	  else{
	    ans[fi]=H(p[fi])+t;
		ans[i]=H(p[i])-t;
	  }
	  vis[fi]=vis[i]=1;
	  fi=0;
	}
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
	  ll* k=lower_bound(key+1,key+key[0]+1,H(p[i]));
	  if(D(p[i])==1){
	    k+=1;
		if(k-key>key[0]||H(p[i])+t<*k) ans[i]=H(p[i])+t;
		else ans[i]=*k;
	  }
	  else{
	    ans[i]=H(p[i])-t<=*k?*(k):H(p[i])-t;
		if((k-key==0&&H(p[i])<*k))
	  }
	}
  }
  for(int i=1,p;i<=q;i++){
    p=re();
	printf("%lld\n",ans[p]);
  }
  return 0;
}
