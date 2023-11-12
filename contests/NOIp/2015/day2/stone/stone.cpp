#include <cstdio>

const int N = (int)5e4+5;

int L, n, m;
int a[N];

inline bool check(int mid)
{
	int ret = 0, pre = 0;
	for(int i=1;i<=n;++i)
		if(a[i]-a[pre]<mid) {if(++ret>m) return false;}
		else pre = i;
	return true;
}

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
//	freopen("stone.in","r",stdin);
//	freopen("stone.out","w",stdout);
	L = re(); n = re(); m = re();
	for(int i=1;i<=n;++i) a[i] = re(); a[++n] = L;
	
	int l = 0, r = L+1, mid;
	int ans;
	while(r-l>1)
	{
		mid = (l+r)>>1;
		if(check(mid))
		{
			ans = mid;
			l = mid;
		}
		else r = mid;
	}
	printf("%d\n",ans);
	return 0;
}
