#include <cstdio>
#include <cstring>
const int N = 205;
int a, b, f, k;
int ans;
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar())if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = x*10+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	a = re(); b = re(); f = re(); k = re();
	if(k==1 && (f>b||a-f>b)) {printf("-1"); return 0;}
	if(k==2 && (f>b||(a-f)*2>b)) {printf("-1"); return 0;}
	if(k>2 && (f*2>b||(a-f)*2>b)) {printf("-1"); return 0;}
	int tmp = b;
	int d[2];
	d[0] = a-f; d[1] = f;
	for(int i = 1; i <= k; ++i) {
		bool p = i&1;
		if(i<k && tmp<d[p]+d[p^1]*2) {
			tmp = b-d[p^1];
			++ans;
		}
		else if(i==k && tmp<a) {
			tmp = b-d[p^1];
			++ans;
		}
		else tmp -= a;
	}
	printf("%d\n", ans);
	return 0;
}
