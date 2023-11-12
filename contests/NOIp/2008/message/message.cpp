#include <cstdio>
#include <cstring>
#define Max(a,b) ((a)>(b)? (a):(b))
const int N = 55, M = 55;
int n, m, pic[N][M];
int f[N][M][N][M];
inline int re() {
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void init() {
	n = re(); m = re();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			pic[i][j] = re();
}

inline void solve() {
	for(int a = 1; a <= n; ++a)
		for(int b = 1; b <= m; ++b)
			for(int c = 1; c <= n; ++c)
				for(int d = 1; d <= m; ++d) {
					if(a==c && b==d) continue;
					int a[2]={a,a+1}, b[2]={b+1,b};
					int c[2]={c,c+1}, d[2]={d+1,d};
					int F=f[a][b][c][d];
					for(int k=0;k<=1;++k)
						for(int t=0;t<=1;++t)
							f[a[k]][b[k]][c[t]][d[t]] = Max(F+pic[a[k]][b[k]][c[t]][d[t]],f[a[k]][b[k]][c[t]][d[t]]);
				}
	printf("%d\n",f[n][m][n][m]);
}

int main() {
	init();
	solve();
	return 0;
}