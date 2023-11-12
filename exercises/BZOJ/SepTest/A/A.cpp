#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N = int(1e5)+5;
int n;
ll m;
int b[N];
ll g[65][2];

inline int re {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re(); m = re();
	int maxb=0, lim=0;
	rep(i,1,n) {b[i]=re(); maxb=max(b[i],maxb);}
	while(maxb){maxb>>=1; ++lim;}
	rep(i,0,lim)
		rep(j,1,n) {
			g[i][0] += (b[i]>>i)&1==0;
			g[i][1] += (b[i]>>i)&1==1;
		}
	rep(i,0,lim) {g[i][0]=1<<g[i][0]; g[i][1]=1<<g[i][1];}

	

	return 0;
}