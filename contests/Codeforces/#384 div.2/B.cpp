#include <cstdio>
#define For(i,a) for(int i=0;i<a;i++)
#define Forr(i,a) for(int i=a;i>=0;i--)
typedef long long ll;
inline ll re(){
	ll x=0; char ch;
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-48;
	return x;
}

#define Mid mid=(l+r)>>1
int n,t;
ll k,l=1,r,mid;
ll quickwork(int n){
	int b=1;
	ll m=2,key=1;
	while(b<=n){
		if(n&b)key*=m;
		m*=m;
		b*=2;
	}
	return key;
}
int main()
{
	n=re(); k=re(); t=n;
	r=quickwork(n)-1;
	while(l<=r){
		Mid;
		if(mid==k)break;
		else if(mid<k)l=mid+1;
		else r=mid-1;
		t--;
	}
	printf("%d",t);
	return 0;
}
