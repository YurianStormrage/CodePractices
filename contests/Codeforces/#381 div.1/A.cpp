#include <cstdio>
#include <algorithm>
using namespace std;
#define Min(a,b) (a<b?a:b)
const int maxn=100005;
int n,m;
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=0,l,r;i<m;i++){
		scanf("%d%d",&l,&r);
		ans=Min(ans,r-l+1);
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d ",i%ans);
	return 0;
}
