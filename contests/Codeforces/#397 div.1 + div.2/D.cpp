#include <cstdio>
inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-') f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - 48;
	if(f) return x;
	return -x;
}
const int maxn = 100005;
int n;
int f[maxn];
int h[maxn], g[maxn];
inline void pnf(int* a, int len) {
	for(int i = 1; i < len; ++i)printf("%d ",a[i]);
	printf("%d",a[len]);
}
int main() {
	n = re();
	int i;
	for(i = 1; i <= n; ++i) {
		f[i] = re();
		if(f[i] == i) {
			//because g(h(x)) = x
			//so g(x) could get the subscript of x in h()
			//so h(g(x)) = x
			//because h(g(x)) = f(x)  so f(x) = x  (x belongs to h())
			h[++h[0]] = i;
			g[i] = h[0];
		}
	}
	
	for(i = 1; i <= n; ++i) if(f[i] != i) {
		if(f[i] != f[f[i]]) break;   //if f[i] == f[f[i]] , f[i] belongs to h().  else no solution
		g[i] = g[f[i]];
	}
	
	if(i > n) {
		printf("%d\n",h[0]);
		pnf(g, n); printf("\n");
		pnf(h, h[0]);
	}
	else printf("-1");
	return 0;
}
