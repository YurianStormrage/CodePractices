#include <cstdio>

#define Min(a,b) ((a)<(b)? (a):(b))

const int N = (int)2e5+5;

int n, a[N];
int dgr[N], q[N], qh, qt;
bool vis[N];
int ans = (int)1e9;

inline void bfs()
{
	qh = qt = 0;
	for(int i=1;i<=n;++i)
		if(!dgr[i]) vis[q[qt++]=i]=1;
	int p;
	while(qh!=qt)
	{
		p = q[qh++];
		if(--dgr[a[p]]==0) vis[q[qt++]=a[p]]=1;
	}
}

inline void dfs(int p, int len)
{
	vis[p] = 1;
	if(vis[a[p]])
	{
		ans = Min(len, ans);
		return;
	}
	dfs(a[p],len+1);
}

inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(;ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main()
{
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	n = re();
	for(int i=1;i<=n;++i)
	{
		a[i] = re();
		dgr[a[i]]++;
	}
	
	bfs();
	
	for(int i=1;i<=n;++i)
		if(!vis[i]) dfs(i,1);
			
	printf("%d\n",ans);
	return 0;
}
