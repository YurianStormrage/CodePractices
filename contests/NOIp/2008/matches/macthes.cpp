#include <cstdio>
#include <cstring>
const int N = 30;
int n;
int num[1005] = {6,2,5,5,4,5,6,3,7,6};
int ans;
inline int re() {
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void init() {
	n = re();
}

inline void solve() {
	for(int i=0; i<=1000; ++i) {
		int x = i;
		int cost = 0;
		while(x) {
			cost += num[x%10];
			x /= 10;
		}
		num[i] = cost;
	}
	for(int i=0; i<=1000; ++i)
		for(int j=0; j<=1000; ++j)
			if(num[i]+num[j]+num[i+j]==n)
				++ans;
	printf("%d\n",ans);
}

int main() {
	init();
	solve();
	return 0;
}