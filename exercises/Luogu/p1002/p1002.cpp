#include <cstdio>
#include <algorithm>
#define Max(a, b) ((a)>(b)? (a):(b))
#define Min(a, b) ((a)<(b)? (a):(b))
typedef long long ll;
#define N 200005
int n, k;
int f[N];
ll sum[N], g[N];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n = re();
	for(int i=1,j;i<=n;++i) {
		sum[i] = re();
		sum[i] += sum[i-1];
		for(j=i-1;j && g[j]>sum[i]-sum[j];--j);
		g[i] = sum[i]-sum[j]; f[i] = f[j]+i-j-1;
	}
	printf("%d",f[n]);
	return 0;
}
