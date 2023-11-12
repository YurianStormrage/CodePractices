#include <cstdio>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Forr(i,a,b) for(int i=(a);i>=(b);--i)
const int maxn=100005;
int n,a,b;
char s[maxn];
int ans;
int main()
{
	scanf("%d%d%d%s",&n,&a,&b,s);
	--a; --b;
	if(s[a]==s[b])printf("0");
	else printf("1");
	return 0;
}
