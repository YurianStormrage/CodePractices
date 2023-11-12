#include <cstdio>
#define Max(a,b) ((a)>(b)? (a):(b))
#define Min(a,b) ((a)<(b)? (a):(b))
//#define debug(x) printf("%d ",x)
const int N = (int)2e5+5, M = 20+1, inf = (int)1e9;
int n, m;
int a[N];
int sum[N][M];
int f[1<<M];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar())
		if(ch=='-')
			f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar())
		x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re(); m = re();
	for(int i = 1; i <= n; ++i) {
		a[i] = re();
		++sum[i][a[i]];
	}
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			sum[i][j] += sum[i-1][j];

	int lim=(1<<m)-1;
	for(int i=1; i<=lim; ++i)
		f[i] = inf;
	for(int i=1; i <= lim; ++i) {
		int r=0;
		for(int j=1, x=1; j<=m; ++j, x<<=1)
			if(x&i)
				r += sum[n][j];
//		debug(r); printf("\n");
		for(int j=1, x=1; j <= m; j++, x<<=1)
			if(x&i) {
				f[i] = Min(sum[n][j]-sum[r][j]+sum[r-sum[n][j]][j]+f[i^x],f[i]);
//				int k = i; while(k) {printf("%d",k&1); k>>=1;}
//				printf("\n"); debug(j); debug(f[i]); printf("\n");
			}
	}
	printf("%d\n",f[lim]);
	return 0;
}
