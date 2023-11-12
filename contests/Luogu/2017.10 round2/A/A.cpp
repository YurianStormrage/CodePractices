#include <cstdio>
typedef long long ll;
const int N = (int)2e5+5, M = (int)2e5+5, mo = 19260817;
int n, m;
ll dist[N], sum1[N], sum2[N];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
//	freopen("sample.in","r",stdin);
//	freopen("A.out","w",stdout);
	n = re(); m = re();
	for(int i=2;i<=n;++i) {
		dist[i] = re();
		dist[i] = (dist[i]+dist[i-1])%mo;
	}
	for(int i=1;i<=n;++i) {
		sum2[i] = re();
		sum1[i] = (sum2[i]*dist[i]+sum1[i-1])%mo;
		sum2[i] = (sum2[i]+sum2[i-1])%mo;
	}
	
	int x, l, r;
	while(m--) {
		x = re(); l = re(); r = re();
		if(x >= r)
			printf("%lld\n",((sum2[r]-sum2[l-1]+mo)%mo*dist[x]%mo-(sum1[r]-sum1[l-1]+mo)%mo+mo)%mo);
		else if(x <= l)
			printf("%lld\n",((sum1[r]-sum1[l-1]+mo)%mo-(sum2[r]-sum2[l-1]+mo)%mo*dist[x]%mo+mo)%mo);
		else
			printf("%lld\n",((sum2[x]-sum2[l-1]+mo)%mo*dist[x]%mo-(sum1[x]-sum1[l-1]+mo)%mo+mo+(sum1[r]-sum1[x]+mo)%mo-(sum2[r]-sum2[x]+mo)%mo*dist[x]%mo+mo)%mo);
	}
	return 0;
}
