#include <cstdio>
#define Min(a,b) ((a)<(b)? (a):(b))
const int N = 1005;
int n, a[N];
int minnum[N];
int clr[N];
int now=1, cnt;
int stk[2][N];
char ans[N<<1];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0';ch=getchar()) if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9';ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline bool build() {
	/*
	The correct way to mark the nodes is that connecting each two nodes which aren't able to be in the same stack
	and then running dfs/bfs to color the nodes.
	The cost of time is O(n)

	The way here takes O(n^2).
	*/
	for(int i=2;i<n;++i)
		for(int j=1;j<i;++j)
			if(minnum[i+1]<a[j] && a[j]<a[i]) {
				if(clr[j] == clr[i]) {
					if(!clr[j]) clr[j] = 1, clr[i] = 2;
					else return false;
				}
				else {
					if(!clr[j]) clr[j] = clr[i]==2? 1:2;
					if(!clr[i]) clr[i] = clr[j]==2? 1:2;
				}
			}
	return true;
}

inline void init() {
	n = re();
	for(int i=1;i<=n;++i) {
		a[i] = re();
		minnum[i] = a[i];
	}
	
	for(int i=n-1;i>=1;--i)
		minnum[i] = Min(minnum[i], minnum[i+1]);
}

inline void pop(bool p) {
	while(stk[p][0] && stk[p][stk[p][0]]==now) {
		ans[++cnt] = p? 'd':'b';
		++now;
		--stk[p][0];
	}
}

inline void push(int x, bool p) {
	ans[++cnt] = p? 'c':'a';
	stk[p][++stk[p][0]] = x;
}

inline void solve() {
	if(!build()) {printf("0"); return;}
	
//	for(int i=1;i<=n;++i) printf("%d ",clr[i]); printf("\n");

	for(int i=1;i<=n;++i) {
		bool p = clr[i]==1 || !clr[i];
		pop(0);
		if(p) push(a[i], 0);
		pop(1);
		if(!p) push(a[i], 1);
	}
	while(stk[0][0] || stk[1][0]) {
		pop(0);
		pop(1);
	}

	for(int i=1;i<=cnt;++i)
		printf("%c ",ans[i]);
}

int main() {
//	freopen("twostack.in","r",stdin);
//	freopen("twostack.out","w",stdout);
	init();
	solve();
	return 0;
}
