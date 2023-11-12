#include <cstdio>
int n;
int pic[45][45];
inline int re()
{
	int x = 0; char ch=getchar(); bool f = 0;
	for(;ch>'9'||ch<'0'; ch=getchar()) if(ch=='-') f = 1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n = re();
	pic[1][(1+n)>>1] = 1;
	int px = 1, py = (1+n)>>1;
	int k = 2, x, y;
	while(k<=n*n)
	{
		if(px==1&&py!=n) {x = n; y = py+1;}
		else if(px!=1&&py==n) {x = px-1; y = 1;}
		else if(px==1&&py==n) {x = px+1; y = py;}
		else 
		{
			if(!pic[px-1][py+1]) {x = px-1; y = py+1;}
			else {x = px+1; y = py;}
		}
		pic[x][y] = k++;
		px = x; py = y;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",pic[i][j]);
		printf("\n");
	}
	return 0;
}
