#include <cstdio>
#include <cstring>
const int maxn = 105, maxm = 105;
int n, m, k;
char pic[maxn][maxm];
int ans;
int main() {
	scanf("%d%d%d", &n,&m,&k);
	for(int i = 1; i <= n; ++i)
		scanf("%s", pic[i]+1);
	
	int sum;
	for(int i = 1; i <= n; ++i) {
		sum = 0;
		for(int j = 1; j <= m; ++j) {
			if(pic[i][j] == '.') ++sum;
			else {
				if(sum >= k) ans += sum - k + 1;
				sum = 0;
			}
		}
		if(sum >= k) ans += sum - k + 1;
	}
	for(int i = 1; i <= m; ++i) {
		sum = 0;
		for(int j = 1; j <= n; ++j) {
			if(pic[j][i] == '.') ++sum;
			else {
				if(sum >= k) ans += sum - k + 1;
				sum = 0;
			}
		}
		if(sum >= k) ans += sum - k + 1;
	}
	//k = 1时ans重复两倍
	if(k == 1)ans >>= 1;
	printf("%d", ans);
	return 0;
}
