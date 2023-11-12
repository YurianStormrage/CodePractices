#include <cstdio>
inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-') f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - 48;
	if(f) return x;
	return -x;
}
int k, a, b;
int ansa = 0, ansb = 0;
int main() {
	k = re(); a = re(); b = re();
	ansa = a / k; ansb = b / k;
	if(!(ansa + ansb) || a % k > ansb * k || b % k > ansa * k)printf("-1");
	else printf("%d", ansa + ansb);
	return 0;
}
