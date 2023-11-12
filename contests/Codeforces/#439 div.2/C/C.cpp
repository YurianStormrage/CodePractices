#include <cstdio>
#define Max(a,b) ((a)>(b)? (a):(b))
#define Min(a,b) ((a)<(b)? (a):(b))
typedef long long ll;
const int E = 5005, mo = 998244353;
int num[4];
//int C[E][E];
int fact[E], p[E];
int inv[E];
int ans;

inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

inline void init() {
	for(int i=0;i<3;++i) num[i] = re(); num[3] = num[0];
	int lim = Max(num[0],num[1]); lim = Max(num[2],lim);
	fact[0] = 1;
	for(int i=1;i<=lim;++i) fact[i] = (ll)i*fact[i-1]%mo;
	inv[1] = 1; for(int i=2;i<=lim;++i) inv[i] = (ll)(mo-mo/i)*inv[mo%i]%mo;
/*
	C[0][0] = 1;
	for(int i=1;i<=lim;++i) {
		C[i][0] = C[i][i] = 1;
		for(int j=1;j<i;++j)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%mo;
	}

*/
}

inline void solve() {
	ans = 1;
	for(int i=0;i<3;++i) {
		int tmp = 1;
		int C1 = 1, C2 = 1;
		for(int k=1,lim=Min(num[i],num[i+1]);k<=lim;++k) {
			C1 = (ll)C1*(num[i]-k+1)%mo*inv[k]%mo;
			C2 = (ll)C2*(num[i+1]-k+1)%mo*inv[k]%mo;
			tmp = (tmp+(ll)C1*C2%mo*fact[k]%mo)%mo;
//			tmp = (tmp+(ll)C[num[i]][k]*C[num[i+1]][k]%mo*fact[k]%mo)%mo;
//			if(C1!=C[num[i]][k]) printf("C1=%d difference at %d %d C[%d][%d]=%d\n",C1, num[i],k,num[i],k,C[num[i]][k]);
//			if(C2!=C[num[i+1]][k]) printf("C2=%d difference at %d %d C[%d][%d]=%d\n",C2, num[i+1],k,num[i+1],k,C[num[i+1]][k]);
//			printf("C[%d][%d]=%d C[%d][%d]=%d k!=%d tmp=%d\n",num[i],k,C1,num[i+1],k,C2,fact[k],tmp);
		}
//		printf("tmp=%d\n",tmp);
		ans = (ll)ans*tmp%mo;
	}
	printf("%d\n",ans);
}

int main() {
	init();
	solve();
	return 0;
}
