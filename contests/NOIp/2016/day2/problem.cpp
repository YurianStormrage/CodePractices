#include <cstdio>
inline int re(){
	int x=0;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-48;
	return x;
}
const int maxn=2005,maxm=2005;
int T;
int n,m,k;
int f[maxn][maxm];
int ans[maxn][maxm];
int main()
{
	T=re(); k=re();
	for(int i=0;i<=2000;i++)//杨辉三角的第一层是(0,0)!
		f[i][0]=1;
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%k;//膜k是关键
	//求组合数的杨辉三角 貌似举几个例子才能想到
	/*
	下面的代码也能求:
	inline int getnum(int i,int j){
		if(i==j)return c[i][j]=1;
		if(c[i][j]!=-1)return c[i][j]%k;
		c[i][j]=getnum(i-1,j)*i/(i-j)%k;
		return c[i][j]%k;
	}
	*/
	
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=2000;j++){
			if(i>=j)
				ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+(!f[i][j]?1:0);
			else
				ans[i][j]=ans[i][j-1];
		}
	
	int a,b;
	while(T--){
		a=re(); b=re();
		printf("%d\n",ans[a][b]);
	}
	return 0;
}
