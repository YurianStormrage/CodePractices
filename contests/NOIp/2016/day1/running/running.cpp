#include <cstdio>
#include <vector>
using namespace std;

const int N = (int)3e5+5, M = (int)3e5+5;

struct Egde
{
	int nxt, to;
	Edge(int _n,_t):nxt(_n),to(_t){}
};

int n, m;
int dep[N], fa[N], sz[N], idx[N], dfn[N];
int lca[M];
int hd[N], egtot;
Edge eg[N];
struct Question{int l,r;} qs[M];
int ans[N];

inline int re()
{
	int x=0; char ch=getchar(); bool f=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void addedge(int u, int v)
{
	eg[++egtot] = Edge(hd[u],v); hd[u] = egtot;
	eg[++egtot] = Edge(hd[v],u); hd[v] = egtot;
}

namespace Tarjan
{
	Edge Eg[M];
	int Hd[N], Egtot;
	int fa[N], rank[N];
	bool vis[N];
	
	inline int Get_fa(int x) {return x==fa[x]? x:fa[x]=Get_fa(fa[x]);}
	inline void Union(int a, int b)
	{
		if(rank[a]<rank[b])
		{
			rank[Get_fa(b)] += rank[Get_fa(a)];
			fa[Get_fa(a)] = Get_fa(b);
		}
		else
		{
			rank[Get_fa(a)] += rank[Get_fa(b)];
			fa[Get_fa(b)] = Get_fa(a);
		}
	}
	inline void addedge(int u, int v) {Eg[++egtot] = Edge(Hd[u],v); Hd[u] = Egtot;}
	
	inline void dfs(int u)
	{
		vis[u] = true;
		fa[u] = u;
		for(int i=hd[u],v;i;i=eg[i].nxt)
		{
			v = eg[i].to;
			if(!fa[v]) dfs(v);
		}
		for(int i=Hd[u],v;i;i=Eg[i].nxt)
		{
			v = u==qs[Eg[i].to].l? qs[Eg[i].to].r : qs[Eg[i].to].l;
			if(vis[v]) lca[eg[i].to] = Get_fa(v);
		}
	}
	
	inline void solve()
	{
		for(int i=1;i<=n;++i) vis[i] = false;
		dfs(1);
	}
}

inline void dfs(int u)
{
	idx[++idx[0]] = u; dfn[u] = idx[0];
	sz[u] = 1;
	for(int i=hd[u],v;i;i=eg[i].nxt)
	{
		v = eg[i].to;
		if(v!=fa[u])
		{
			dep[v] = dep[u]+1;
			fa[v] = u;
			dfs(v);
			sz[u] += sz[v];
		}
	}
}

struct Two{int x,y;Two(int _x,int_y):x(_x),y(_y){}};
vector<Two> smb1[N], smb2[N];
#define pb(x) push_back(x)

inline void mark1(int l, int r, int d)
{
	smb1[l].pb(Two(d,1));
	smb1[r].pb(Two(d,-1));
}

inline void mark2(int l, int r, int d)
{
	smb2[l].pb(Two(d,1));
	smb2[r].pb(Two(d,-1));
}

inline void prework()
{
	Tarjan::solve();
	dfs(1);
	for(int i=1,u,v,t,L;i<=m;++i)
	{
		u = qs[i].l; v = qs[i].r; t = lca[i];
		L = d[u]+d[v]-(d[t]<<1);
		if(u!=t&&v!=t) mark1(u,t,d[u]), mark2(v,fa[t],L-d[u]);
		else dep[u]>dep[v]? mark1(u,fa[v],d[u]):mark2(v,fa[u],-d[u]);
	}
}

vector<Two> 

inline void solve()
{
	
}

int main()
{
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	n = re(); m = re();
	for(int i=1;i<n;++i) addedge(re(),re());
	for(int i=1;i<=m;++i)
	{
		qs[i].l=re(); qs[i].r=re();
		Tarjan::addedge(qs[i].l,i);
		Tarjan::addedge(qs[i].r,i);
	}
	
	prework();
	
	solve();
	
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}
