#include <cstdio>
const int maxn = 200005;
int n, m[2], q;
int a[maxn];
long long ans;
inline void update(int x, int y, int z) {
	int l = a[x-1];
	ans -= (l - a[x]) * m[l>a[x]];
	ans += (l - a[x] - z) * m[l>(a[x]+z)];
	if(y < n) {
		int r = a[y+1];
		ans -= (a[y] - r) * m[a[y]>r];
		ans += (a[y]+z - r) * m[(a[y]+z)>r];
	}
	a[x] += z; a[y] += z;
}

inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-')f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = (x<<1) + (x<<3) + ch - 48;
	if(f)return x;
	return -x;
}

int main() {
	n = re(); q = re(); m[0] = re(); m[1] = re();
	for(int i = 0; i <= n; ++i)
		a[i] = re();
	for(int i = 0; i < n; ++i)
		ans += (a[i] - a[i+1]) * m[a[i]>a[i+1]];
	for(int i = 1, x, y, z; i <= q; ++i) {
		x = re(); y = re(); z = re();
		update(x, y, z);
		printf("%lld\n", ans);
	}
	return 0;
}
//(a[i] - a[i+1]) * m[a[i]<a[i+1]]
