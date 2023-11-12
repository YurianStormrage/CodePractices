#include <cstdio>
#include <cstring>
#define abs(x) ((x)<0? -(x):(x))
const int N = (int)1e5+5, M = (int)2e5+5;
int T, n, m;
int in[N], out[N];
bool vis[M];
int hd[N], nxt[M], to[M], id[M], egtot;
int q[M], qt;

inline void addedge(int u, int v, int Id) {nxt[++egtot] = hd[u]; hd[u] = egtot; to[egtot] = v; id[egtot] = Id;}

inline void read(int& x)
{
	x = 0; char ch = getchar(); bool f = 0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') f = 1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) x = -x;
}

inline void dfs(int s)
{
	for(int i=hd[s];i;i=nxt[i])
		if(!vis[abs(id[i])])
		{
			vis[abs(id[i])] = true;
			dfs(to[i]);
			q[qt++] = id[i];
		}
}

int main()
{
	read(T); read(n); read(m);
	if(T == 1)
	{
		for(int i=1,u,v;i<=m;++i)
		{
			read(u); read(v);
			addedge(u, v, i); addedge(v, u, -i);
			++out[u]; ++out[v];
		}
		for(int i=1,cnt=0;i<=n;++i)
			if(out[i]&1) {puts("NO"); return 0;}
	}
	else
	{
		for(int i=1,u,v;i<=m;++i)
		{
			read(u); read(v);
			addedge(u, v, i);
			++out[u]; ++in[v];
		}
		for(int i=1;i<=n;++i)
			if(in[i]!=out[i]) {puts("NO"); return 0;}
	}
	dfs(1);
	if(qt < m || !m) puts("NO");
	else {puts("YES"); for(int i=qt-1;i>=0;--i) printf("%d ",q[i]);}
	return 0;
}