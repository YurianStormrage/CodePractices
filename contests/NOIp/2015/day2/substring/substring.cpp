#include <cstdio>
#include <cstring>

#define Min(a,b) ((a)<(b)?(a):(b))

const int N = 1005, M = 205, K = 205, mo = (int)1e9+7;

int n, m, k;
char a[N], b[M];
int f[2][M][K], g[2][M][K];

inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(; ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main()
{
	freopen("substring.in","r",stdin);
	freopen("substring.out","w",stdout);
	n = re(); m = re(); k = re();
	scanf("%s%s",a,b);
	
	bool cur=0, nxt;
	for(int i=1;i<=n;++i)
	{
		nxt = cur^1;
		g[cur][0][0] = 1;
		for(int j=1,lim=Min(i,m);j<=lim;++j)
		{
			for(int k=1;k<=j;++k)
			{
				f[nxt][j][k] = 0;
				if(a[i-1]==b[j-1]) f[nxt][j][k] = (f[cur][j-1][k]+g[cur][j-1][k-1])%mo;
				g[nxt][j][k] = (g[cur][j][k]+f[nxt][j][k])%mo;
//				printf("f[%d][%d][%d]=%d\n",i,j,k,f[nxt][j][k]);
//				printf("g[%d][%d][%d]=%d\n",i,j,k,g[nxt][j][k]);
			}
		}
		cur ^= 1;
	}
	
	printf("%d\n",g[cur][m][k]);
	return 0;
}
