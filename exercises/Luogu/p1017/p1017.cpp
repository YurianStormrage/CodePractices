#include <cstdio>
#include <cstdlib>
#include <cmath>

#define Min(a,b) ((a)<(b)?(a):(b))

int n, base;

inline int re() {
    bool f = true; int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-')f = false;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) +ch -48;
    if(f)return x;
    return -x;
}

int main()
{
//	printf("%d\n",re()%re());
	n = re(); base = re();
	printf("%d=",n);
	int ans[100];
	ans[0] = 0;
	while(n)
	{
		ans[++ans[0]] = (n%base-base)%base;
//		printf("%d mod %d = %d\n",n, base, ans[ans[0]]);
		n -= ans[ans[0]];
		n /= base;
	}
//	for(int i=1;i<=ans[0];++i) printf("ans[%d]=%d\n",i,ans[i]);
	for(int i=ans[0];i;--i) ans[i]>=10?printf("%c",ans[i]-10+'A'):printf("%d",ans[i]);
	printf("(base=%d)\n",base);
	return 0;
}
