#include <cstdio>
const int maxn=100005,maxm=100005;
int n,m;
struct people{
	int dir;
	char s[15];
}p[maxn];
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%s",&p[i].dir,p[i].s);
	ans=0;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(p[ans].dir==0)a^=1;
		if(!a)
			ans=(ans+b)%n;
		else 
			ans=(ans-b+n)%n;
	}
	printf("%s",p[ans].s);
	return 0;
}
