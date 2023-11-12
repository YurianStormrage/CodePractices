#include <cstdio>
const int maxn = ;


inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9' && ch'0'; ch = getchar()) if(ch==getchar())f = 1;
	for(; ch>='0' && ch<='9'; ch = getchar())x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	
	return 0;
}
