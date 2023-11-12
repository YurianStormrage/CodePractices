#include <cstdio>
#define Min(a,b) (a)<(b)? (a):(b)
const int N = 205, K = 10;
int n, k;
int f[N][K];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) if(ch == '-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re(); k = re();
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i) f[i][1] = 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j<=k && j<=i; ++j)
			f[i][j] = f[i-1][j-1]+f[i-j][j];
	printf("%d\n", f[n][k]);
	return 0;
}
//1.至少有一个盒子只有一个小球的情况数
//因为盒子不加区分，那么情况数与“将n-1个小球放到k-1个盒子中”的情况数一样
//
//2.没有一个盒子只有一个小球的情况数
//没有一个盒子只有一个小球，那么把每个盒子中拿出来一个小球
//对应的是“把(n-k)个小球放到k个盒子中的情况数”