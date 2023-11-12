#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55, M = 10;
int n, m;
int line[N<<1], sum[N<<1];
int f[N<<1][N<<1][M], g[N<<1][N<<1][M];
int main() {
	//freopen("p1218.in","r",stdin);
	//freopen("p1218.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &line[i]);
		line[i+n] = line[i];
	}
	for(int i = 1; i <= n<<1; ++i)
		sum[i] = sum[i-1] + line[i];

	for(int i = 1; i <= (n<<1); ++i)
		for(int len = 1; len <= n; ++len)
			f[i][i-1+len][1] = g[i][i-1+len][1] = ((sum[i-1+len]-sum[i-1])%10+10)%10;
	
	for(int j = 2; j <= (n<<1); ++j) {
		int limi = max(1, j-n+1);
		for(int i = j-1; i >= limi; --i) {
			int limk = min(m, j-i+1);
			for(int k = 2; k <= limk; ++k) {
				f[i][j][k] = int(1e9);
				for(int K = 1; K < k; ++K)
					for(int mid = i; mid < j; ++mid) if(mid-i+1>=K && j-mid>=k-K){
						f[i][j][k] = min(f[i][mid][K]*f[mid+1][j][k-K], f[i][j][k]);
						g[i][j][k] = max(g[i][mid][K]*g[mid+1][j][k-K], g[i][j][k]);
						//printf("%d %d %d  %d %d %d %d %d\n", f[i][j][k], f[i][mid][K], f[mid+1][j][k-K], i, mid, j, k, K);
					}
			}
		}
	}

	int minans = int(1e9), maxans = -int(1e9);
	for(int i = 1; i <= n; ++i) {
		minans = min(minans, f[i][i+n-1][m]);
		maxans = max(maxans, g[i][i+n-1][m]);
	}
	printf("%d\n%d\n", minans, maxans);
	return 0;
}
