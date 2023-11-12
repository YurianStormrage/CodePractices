#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 205, K = 45;
int n, k, p;
char s[N], dic[10][N];
int f[N][K], g[N][N];
int len, slen[N];

inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re(); k = re();
	for(int i = 0; i < n; ++i) scanf("%s",s+i*20);
	len = strlen(s); p = re();
	for(int i = 0; i < p; ++i) scanf("%s",dic[i]);
	
	for(int i = 0; i < len; ++i) slen[i] = N;
	for(int i = 0; i < len; ++i) {
		for(int t = 0; t < p; ++t) {
			int l = 0;
			while(i+l<len && s[i+l]==dic[t][l]) ++l;
			if(l == (int)strlen(dic[t]))
				slen[i]=min(i+l-1,slen[i]);
		}
	}
	
	for(int i = 1; i <= len; ++i)
		for(int j = i; j >= 1; --j)
			g[j][i] = g[j+1][i]+(slen[j-1]<=i-1? 1:0);
			
	for(int j = 1; j<=k; ++j)
		for(int i = j; i <= len; ++i)
			for(int t = i-1; t>=j-1; --t)
				f[i][j] = max(f[t][j-1]+g[t+1][i], f[i][j]);

	printf("%d\n",f[len][k]);
	return 0;
}
