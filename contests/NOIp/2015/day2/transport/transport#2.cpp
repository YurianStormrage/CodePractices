#include <cstdio>
#include <algorithm>

#define ls (p<<1)
#define rs (p<<1|1)
#define Max(a,b) (std::max((a),(b)))

const int N = 300005, M = 300005, inf = (int)1e9;

int n, m;
struct Question{int l,r,d;} Q[M];
int hd[N], nxt[N], to[N], dis[N], egtot;
int seg[N], id[N], top[N], sz[N], dep[N], fa[N], dist[N];
int cnt[N<<2], lazy[N<<2], L[N<<2], R[N<<2];
int mxd, sum[N], vis[M];

inline bool operator<(const Question& a, const Question& b) {return a.d>b.d;}
inline void Swap(int& a, int& b){int tmp=a;a=b;b=tmp;}
inline void addedge(int u, int v, int d)
{
	nxt[++egtot]=hd[u]; hd[u]=egtot; to[egtot]=v; dis[egtot]=d;
	nxt[++egtot]=hd[v]; hd[v]=egtot; to[egtot]=u; dis[egtot]=d;
}

inline int Get_dist(int u, int v)
{
	int ret = 0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) Swap(u,v);
		ret += sum[id[u]]-sum[id[top[u]]]+dist[top[u]];
		u = fa[top[u]];
	}
	if(u == v) return ret;
	if(dep[u]<dep[v]) Swap(u,v);
	return ret+sum[id[u]]-sum[id[v]];
}

inline void dfs1(int p)
{
	sz[p] = 1;
	for(int i=hd[p];i;i=nxt[i]) if(!sz[to[i]])
	{
		dist[to[i]] = dis[i];
		dep[to[i]] = dep[p]+1;
		fa[to[i]] = p;
		dfs1(to[i]);
		sz[p] += sz[to[i]];
	}
}

inline void dfs2(int p)
{
	seg[++seg[0]] = p; id[p] = seg[0];
	int mx=0, mxi=-1;
	for(int i=hd[p];i;i=nxt[i]) if(!top[to[i]]&&mx<sz[to[i]])
	{
		mx = sz[to[i]];
		mxi = to[i];
	}
	
	if(mxi==-1) return;
	top[mxi] = top[p];
	dfs2(mxi);
	for(int i=hd[p];i;i=nxt[i]) if(!top[to[i]])
	{
		top[to[i]] = to[i];
		dfs2(to[i]);
	}
}

inline void pushdown(int p)
{
	if(lazy[p]==0) return;
	lazy[ls] += lazy[p];
	lazy[rs] += lazy[p];
	cnt[ls] += lazy[p];
	cnt[rs] += lazy[p];
	lazy[p] = 0;
}

inline void update(int p) {cnt[p] = Max(cnt[ls], cnt[rs]);}

inline void build(int p, int l, int r)
{
	L[p] = l; R[p] = r;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
}

inline void init(int p)
{
	cnt[p]=0; lazy[p]=0;
	if(L[p]==R[p]) return;
	init(ls);
	init(rs);
}

inline void modify(int p, int l, int r)
{
	if(l==L[p]&&R[p]==r)
	{
		cnt[p]++; lazy[p]++;
		return;
	}
	pushdown(p);
	int mid = (L[p]+R[p])>>1;
	if(r<=mid) modify(ls,l,r);
	else if(l>mid) modify(rs,l,r);
	else modify(ls,l,mid), modify(rs,mid+1,r);
	update(p);
}

inline void query(int p, int num)
{
	if(L[p]==R[p])
	{
		mxd = Max(dist[seg[R[p]]], mxd);
		cnt[p] = 0; lazy[p] = 0;
		return;
	}
	pushdown(p);
	if(cnt[ls]==num) query(ls,num);
	if(cnt[rs]==num) query(rs,num);
	update(p);
}

inline void mark(int u, int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) Swap(u,v);
		modify(1,id[top[u]],id[u]);
		u = fa[top[u]];
	}
	if(u == v) return;
	if(dep[u]<dep[v]) Swap(u,v);
	modify(1,id[v]+1,id[u]);
}

inline int binary(int x)
{
	int l = 0, r = m+1, mid, ret=0;
	while(r-l>1)
	{
		mid = (l+r)>>1;
		if(Q[mid].d>x)
		{
			ret = mid;
			l = mid;
		}
		else r = mid;
	}
	return ret;
}

inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void prework()
{
	build(1,1,n);
	dfs1(1);
	top[1] = 1; dfs2(1);
	for(int i=2;i<=seg[0];++i) sum[i] = sum[i-1]+dist[seg[i]];
	for(int i=1;i<=m;++i)
		Q[i].d = Get_dist(Q[i].l,Q[i].r);
	std::sort(Q+1,Q+1+m);
	for(int i=1;i<=m;++i) vis[i] = -1;
}

inline bool check(int mid)
{
	int num = binary(mid);
	if(~vis[num]) return Q[1].d-vis[num]<=mid;
	init(1);
	for(int i=1;i<=num;++i) mark(Q[i].l,Q[i].r);
	mxd = 0; query(1,num);
	vis[num] = mxd;
	return Q[1].d-mxd<=mid;
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
	for(int i=1;i<=m;++i) {Q[i].l=re(); Q[i].r=re();}
	
	prework();
	
	int l = 0, r = Q[1].d+1, mid;
	int ans;
	while(r-l>1)
	{
		mid = (l+r)>>1;
		if(check(mid))
		{
			ans = mid;
			r = mid;
		}
		else l = mid;
	}
	printf("%d\n",ans);
	return 0;
}
