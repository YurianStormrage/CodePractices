#include <cstdio>
const int maxn = 105, maxm = 305, inf = int(1e9);
int n, m, num_v;
int s, t;
int tot, last[maxn];
struct edge {
	int from, to, c, nxt;
	edge() {}
	edge(int _f, int _t, int _c, int _n): from(_f), to(_t), c(_c), nxt(_n){}
}eg[maxm << 2];

int q[maxn], qh, qt;
int dis[maxn], cur[maxn];
int path[maxn], p_n;

inline bool BFS(int s, int t, int n) {
	for(int i = 1; i <= n; ++i)
		dis[i] = inf;
	qh = 0; qt = 1;
	q[qh] = s;
	dis[s] = 0;
	
	int x, y;
	while(qh != qt) {
		x = q[qh++];
		for(int i = last[x]; ~i; i = eg[i].nxt) {
			y = eg[i].to;
			if(eg[i].c && dis[y] == inf) {
				dis[y] = dis[x] + 1;
				if(y == t)return true;
				q[qt++] = y;
			}
		}
	}
	return false;
}

inline int Dinic(int s, int t, int flow, int n) {
	path[p_n++] = s;
	int x = s;
	while(BFS(s, t, n)) {
		for(int i = s; i <= t; ++i) 
			cur[i] = last[i];
		while(true) {
			if(x == t) {
				int f = inf, mini = -1;
				for(int i = 0; i < p_n; ++i)
					if(f > eg[cur[path[i]]].c)
						f = eg[cur[path[i]]].c, mini = i;
				for(int i = 0; i < p_n; ++i) {
					eg[cur[path[i]]].c -= f;
					eg[cur[path[i]]^1].c += f;
				}
				x = path[mini]; p_n = mini + 1;
				flow += f;
			}
			int i;
			for(i = cur[x]; ~i; i = eg[i].nxt)
				if(eg[i].c && dis[eg[i].to] == dis[x] + 1)
					break;
			cur[x] = i;
			if(~i) {
				x = eg[i].to;
				path[p_n++] = x;
			}
			else {
				if(!p_n)break;
				x = path[--p_n];
			}
		}
	}
	return flow;
}

inline void addedge(int u, int v, int c) {
	eg[tot] = edge(u, v, c, last[u]); last[u] = tot++;
	eg[tot] = edge(v, u, 0, last[v]); last[v] = tot++;
}

inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-')f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - 48;
	if(f) return x;
	return -x;
}
int main() {
	n = re(); m = re();
	
	s = 1; t = n + 1;
	for(int i = 1; i <= n; ++i)
		last[i] = -1;
	
	for(int i = 1, u, v, c; i <= m; ++i) {
		u = re(); v = re(); c = re();
		addedge(u, v, c);
		addedge(v, u, c);
	}
	num_v = re();
	for(int i = 1, x; i <= num_v; ++i) {
		x = re();
		addedge(x, t, inf);
	}
	printf("%d",Dinic(s, t, 0, t));
	return 0;
}
