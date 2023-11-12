#include <cstdio>
#define Min(a, b) ((a)<(b)? (a):(b))
const int N = 2005, M = 2005, inf = (int)1e9;
int n, m;
int pic[N][M], num[0][N][M];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	n = re(); m = re();

	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			pic[i][j] = re();
		}
	}



	for(int i=1;i<n;++i)
		for(int j=0;j<=i;++j) {
			tmp[0][i][j] = 
		}
	return 0;
}
