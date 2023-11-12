#include <cstdio>
#define Min(a, b) (a < b ? a : b)
const int maxn = 2005, maxm = 2005, maxv = 305, inf = int(1e9);
int n, m, v, e;
int pic[maxv][maxv];
int dis[maxn][2];
double k[maxn];
double f;

inline int re() {
	int x = 0; char ch = getchar(); bool f = 1;
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-')f = 0;
	for(; ch >='0' && ch <='9'; ch = getchar())x = (x<<1) + (x<<3) + ch - 48;
	if(f)return x;
	return -x;
}

inline void init() {
	n = re(); m = re(); v = re(); e = re();
	for(int i = 1; i <= n; ++i)	dis[i][0] = re();
	for(int i = 1; i <= n; ++i)	dis[i][1] = re();
	for(int i = 1; i <= n; ++i) scanf("%llf",&k[i]);
	
	for(int i = 1; i < v; ++i)
		for(int j = i+1; j <= v; ++j)
			pic[i][j] = pic[j][i] = inf;
	
	for(int i = 1, u, v, w; i <= e; ++i){
		u = re(); v = re(); w = re();
		if(pic[u][v] > w)
			pic[u][v] = pic[v][u] = w;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(pic[i][j] > pic[i][k] + pic[k][j])
					pic[i][j] = pic[i][k] + pic[k][j];
}


int main() {
	init();
	
	return 0;
}
