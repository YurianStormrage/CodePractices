#include <cstdio>

inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main()
{
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	n = re(); m = re();
	for(int i=1,u,v,d;i<n;++i)
	{
		u = re(); v = re(); d = re();
		addedge(u,v,d);
	}
	for(int i=1;i<=m;++i)
	{
		s
	}
	return 0;
}
