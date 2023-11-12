#include <cstdio>
#include <cstring>
const int N = (int)2e5+5;
int n, a[N];
int vis[N], used[N];
int que[N], qh, qt;
int ans;
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar())if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = x*10+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re();
	for(int i = 1; i <= n; ++i) {
		a[i] = re();
		++vis[a[i]];
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			que[qt++] = i;
	for(int i = 1; i <= n; ++i) {
		if(qh==qt) break;
		if(used[a[i]]) {--vis[a[i]]; a[i]=que[qh++]; ++ans;}
		else if(vis[a[i]]==1 || que[qh]>a[i]){--vis[a[i]]; used[a[i]]=1;}
		else {--vis[a[i]]; a[i]=que[qh++]; ++ans;}
	}
	printf("%d\n",ans);
	for(int i = 1; i <= n; ++i)printf("%d ",a[i]);
	return 0;
}
