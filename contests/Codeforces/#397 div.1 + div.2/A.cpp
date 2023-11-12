#include <cstdio>
inline int re() {
	bool f = 1; int x = 0; char ch = getchar();
	for(; ch > '9' || ch < '0'; ch = getchar())if(ch == '-') f = 0;
	for(; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - 48;
	if(f) return x;
	return -x;
}
int n;
char s[10];
int main() {
	n = re();
	scanf("%s",s);
	for(int i = 0; i < n; ++i)scanf("%s",s);
	if(n & 1)printf("contest");
	else printf("home");
	return 0;
}
