#include <cstdio>
typedef long long ll;
#define Max(a, b) ((a)>(b)?(a):(b))
const int N = 500005;
int n, s;
int head[N], next[N<<1], d[N<<1], to[N<<1];
inline void addedge(int u, int v, int D) {next[++egtot]=head[u]; head[u]=egtot; d[egtot]=D; to[egtot]=v;}
ll sum[N];
int dad[N], arr[N], up[N];
bool vis[N], inque[N];
int que[N], qh;
ll maxd = 0, tmp = 0, dis[N], ans = 0;
int maxid;

int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9' || ch<'0'; ch = getchar()) if(ch == '-') f = 1;
	for(; ch>='0' && ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline int lowerbound(int l, int r, int k) {
	int mid;
	while(l <= r) {
		mid = (l+r)>>1;
		if((sum[mid]<<1) >= k) r = mid-1;
		else l = mid+1;
	}
	return l;
}

void dfs(int p, int fa) {
	for(int i = head[p]; i; i = next[i]) if(to[i] != fa){
		tmp += d[i];
		if(tmp > maxd) {maxid=to[i]; maxd=tmp;}
		dfs(to[i], p);
		tmp -= d[i];
	}
}
void dfs2(int p, int fa) {
	dad[p] = fa;
	for(int i = head[p]; i; i = next[i]) if(to[i] != fa){
		tmp += d[i];
		if(tmp > maxd) {maxid=to[i]; maxd=tmp;}
		up[to[i]] = d[i];
		dfs(to[i], p);
		tmp -= d[i];
	}
}

inline void bfs(int p) {
	que[qh++] = p;
	inque[p] = 1;
	int pt;
	while(qh) {
		pt = que[--qh];
		for(int i = head[pt]; i; i = next[i]) 
			if(!inque[to[i]] && !vis[to[i]]) {
				dis[to[i]] = dis[pt]+d[i];
				ans = Max(dis[to[i]], ans);
				que[qh++] = to[i];
				inque[to[i]] = 1;
			}
	}
	inque[p] = 0;
}

int main() {
	n = re(); s = re();
	for(int i=1, u, v, D; i < n; ++i) {
		u = re(); v = re(); D = re();
		addedge(u, v, D);
		addedge(v, u, D);
	}
	
	int lp, rp;
	dfs(1, 0); lp = maxid;
	maxd = 0; tmp = 0;
	dfs2(lp, 0); rp = maxid;
	for(int i = rp; i; i = dad[i]) {
		sum[++sum[0]] = sum[sum[0]-1]+up[i];
		arr[++arr[0]] = i;
		vis[i] = 1;
	}

	int ctr = lowerbound(1, sum[0], maxd);
	ll len = 0;
	for(int l = 1, r = 1, rr; l <= ctr; ++l) {
		while(sum[r+1]-sum[l] <= s) ++r;
		for(int i = l+1; i < r; ++i)
			bfs(i);
		ans = Max(sum[l], ans);
		ans = Max(sum[sum[0]]-sum[r], ans);
	}
	printf("%lld", ans);
	return 0;
}
