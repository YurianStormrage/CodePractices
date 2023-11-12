#include <cstdio>
const int N = (int)2e5+5, M = 20+5;
int n;
int a[N];
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
	n = re();
	for(int i = 1; i <= n; ++i)
		a[i] = re();
	
	return 0;
}
