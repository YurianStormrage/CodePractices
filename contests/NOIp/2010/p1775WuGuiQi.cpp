#include <cstdio>
#define Max(a,b) a>b?a:b
const int maxn=500;
int n,m;
int f[45][45][45][45];
int a[maxn],b[5];
inline int re(){
	int x=0; char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-48;
	return x;
}
int main()
{
	n=re(); m=re();
	for(int i=1;i<=n;i++)a[i]=re();
	for(int i=1;i<=m;i++)b[re()]++;
	for(int i1=0;i1<=b[1];i1++)
		for(int i2=0;i2<=b[2];i2++)
			for(int i3=0;i3<=b[3];i3++)
				for(int i4=0;i4<=b[4];i4++){
					if(i1)f[i1][i2][i3][i4]=Max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]);
					if(i2)f[i1][i2][i3][i4]=Max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]);
					if(i3)f[i1][i2][i3][i4]=Max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]);
					if(i4)f[i1][i2][i3][i4]=Max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]);
					f[i1][i2][i3][i4]+=a[i1+(i2<<1)+i3*3+(i4<<2)+1];
				}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}
