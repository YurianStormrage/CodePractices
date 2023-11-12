#include <cstdio>
const int N = 1005;
int n;
int ndtot;
struct node{int a,b,c,d,e;}nd[N];
struct Vector {
	int a,b,c,d,e;
	friend int operator *(Vector x, Vector y) {
		return x.a*y.a+x.b*y.b+x.c*y.c+x.d*y.d+x.e*y.e;
	}
	Vector(){}
	Vector(int A, int B, int C, int D, int E):a(A),b(B),c(C),d(D),e(E){}
}vec[2];
int index[N];
bool bad[N], vis[N];

inline bool check(node x, node y, node z) {
	vec[0]=Vector(y.a-x.a,y.b-x.b,y.c-x.c,y.d-x.d,y.e-x.e);
	vec[1]=Vector(z.a-x.a,z.b-x.b,z.c-x.c,z.d-x.d,z.e-x.e);
	if(vec[0]*vec[1] <= 0) return true;
	return false;
}

inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) 
	if(ch == '-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main() {
	n = re();
	if(n <= 2) {
		printf("%d\n",n);
		for(int i = 1; i <= n; ++i) printf("%d\n",i);
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		nd[++ndtot].a = re();
		nd[ndtot].b = re();
		nd[ndtot].c = re();
		nd[ndtot].d = re();
		nd[ndtot].e = re();
	}
	
	for(int i = 1; i <= n; ++i) if(!bad[i]) {
		for(int j = 1; j < n; ++j) if(j != i)
			for(int k = j+1; k <= n; ++k) if(k != i)
				if(check(nd[i],nd[j],nd[k])) bad[j]=bad[k]=1;
				else bad[i]=1;
		if(!bad[i]) index[++index[0]] = i;
	}
	printf("%d\n",index[0]);
	for(int i = 1; i <= index[0]; ++i) printf("%d\n",index[i]);
	return 0;
}
