#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55;
int n, m;
int line[N<<1], sum[N<<1];
int f[N<<1][N<<1], g[N<<1][N<<1];
int main() {
	freopen("p1218.in","r",stdin);
	//freopen("p1218.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &line[i]);
		line[i+n] = line[i];
	}
	for(int i = 1; i <= n<<1; ++i)
		sum[i] = sum[i-1] + line[i];
	
	for(int i = 1; i <= n; ++i) {
		for(int len = 1; len <= n; ++len) {
			
		}
	}
	int minans = int(1e9), maxans = -int(1e9);
	for(int i = 1; i <= n; ++i) {
		minans = min(minans, f[i][i+n-1]);
		maxans = max(maxans, g[i][i+n-1]);
	}
	printf("%d\n%d\n", minans, maxans);
	return 0;
}
