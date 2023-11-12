#include <cstdio>
inline int re(){
	int x=0; char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-48;
	return x;
}
const int maxm=15,maxn=10005,mod=1000000009;
int T,n,k;
int f[2][maxn];
int main()
{
	T=re();
	while(T--){
	    k=re(); n=re();
	    for(int i=1;(1<<i)<=n;i++){
			
		}
	}
	return 0;
}
