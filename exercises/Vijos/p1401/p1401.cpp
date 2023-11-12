#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define For(i,a) for(int i=0;i<(a);++i)
#define foR(i,a) for(int i=(a)-1;i>=0;--i)
inline int re(){
	int x=0; char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-48;
	return x;
}
const int maxn=int(1e9)+5,maxm=int(1e3)+5;
int n,k,m;
int t;
struct Stop{
	double a,b;
	friend inline bool operator<(Stop a,Stop b)
	{return a.a<b.a;}
}p[maxm];
double ans;
int main()
{
	n=re()-1; k=re(); m=re();
	t=1;
	For(i,m)scanf("%lf%lf",&p[i].a,&p[i].b);
	sort(p,p+m); p[m].a=double(1e9)+5;
	for(int i=0;n>0;){
		while(p[i].a-ans>=1){
			ans+=1;
			n-=t;
			if(n<=0){printf("%.2lf",ans);return 0;}
			t=Min(k,t+t);
		}
		ans=Max(ans,p[i].a+p[i].b);
		if(i<m)i++;
	}
	return 0;
}
