#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 300005;
int n, k;
ll ans;
int a[N];
struct node {
	ll c; int id;
	friend bool operator < (node a, node b) {
		return a.c < b.c;
	}
}nd[N];
priority_queue <node> q;
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) if(ch=='0')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re(); k = re();
	for(int i = 1; i <= n; ++i) nd[i].c = re(), nd[i].id = i;
	for(int i = 1; i <= k; ++i) {
		q.push(nd[i]);
	}
	for(int i = k+1; i <= k+n; ++i) {
		q.push(nd[i]);
		ans += q.top().c*(i-q.top().id);
		a[q.top().id] = i;
		q.pop();
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= n; ++i) printf("%d ",a[i]);
	return 0;
}
