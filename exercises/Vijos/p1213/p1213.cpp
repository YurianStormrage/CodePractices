#include <cstdio>
#include <queue>
#define Min(a, b) (a < b ? a : b)
using namespace std;

const int maxn = 105, maxm = 10101, inf = int(1e9);
int n, m;
int Vn;
int s, t, k;

int tot, last[maxn << 1];
struct edge {
	int from, to, c, d, nxt;
	edge() {}
	edge(int _f, int _t, int _c, int _d, int _n): from(_f), to(_t), c(_c), d(_d), nxt(_n) {}
}e[maxm << 1];

queue <int> q;
int dis[maxn << 1], pos[maxn << 1];
bool inq[maxn << 1];

inline void addedge(int u, int v, int c, int d) {
	e[tot] = edge(u, v, c, d, last[u]);
	last[u] = tot++;
	e[tot] = edge(v, u, 0, -d, last[v]);
	last[v] = tot++;
}

inline bool spfa(int s, int t) {
	for(int i = 0; i <= Vn; ++i)
		dis[i] = inf, inq[i] = 0, pos[i] = -1;
	q.push(s);
	inq[s] = 1; pos[s] = 0;
	dis[s] = 0;
	int x, y;
	while(!q.empty()) {
		x = q.front(); q.pop();
		inq[x] = 0;
		for(int i = last[x]; ~i; i = e[i].nxt) {
			y = e[i].to;
			if(e[i].c && dis[y] > dis[x] + e[i].d) {
				dis[y] = dis[x] + e[i].d;
				pos[y] = i;
				if(!inq[y]) {
					inq[y] = 1;
					q.push(y);
				}
			}
		}
	}
	return dis[t] != inf;
}

inline int MCMF(int s, int t) {
	int cost = 0;
	while(spfa(s, t)){
		int tmp = inf;
		for(int i = t; i != s; i = e[pos[i]].from)
			 tmp = Min(tmp, e[pos[i]].c);
		for(int i = t; i != s; i = e[pos[i]].from) {
			e[pos[i]].c -= tmp;
			e[pos[i]^1].c += tmp;
		}
		cost += tmp * dis[t];
	}
	return cost;
}

inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-')f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - 48;
	if(f)return x;
	return -x;
}

inline void init() {
	Vn = (n << 1) + 2;
	s = 0; t = (n << 1) + 1; k = t + 1;
	for(int i = 0; i <= Vn; ++i)
		last[i] = -1;
}

int main() {
	n = re(); m = re();
	init();
	addedge(s, k, m, 0);
	for(int i = 1, c; i <= n; ++i){
		c = re();
		addedge(s, i, c, 0);
		addedge(i + n, t, c, 0);
		addedge(k, i + n, inf, 0);
	}
	for(int i = 1, d; i < n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			d = re();
			if(~d)
				addedge(i, j + n, inf, d);
		}
	printf("%d",MCMF(s, t));
	return 0;
}
